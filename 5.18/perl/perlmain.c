/*    miniperlmain.c
 *
 *    Copyright (C) 1994, 1995, 1996, 1997, 1999, 2000, 2001, 2002, 2003,
 *    2004, 2005, 2006, 2007, by Larry Wall and others
 *
 *    You may distribute under the terms of either the GNU General Public
 *    License or the Artistic License, as specified in the README file.
 *
 */

/*
 *      The Road goes ever on and on
 *          Down from the door where it began.
 *
 *     [Bilbo on p.35 of _The Lord of the Rings_, I/i: "A Long-Expected Party"]
 *     [Frodo on p.73 of _The Lord of the Rings_, I/iii: "Three Is Company"]
 */

/* This file contains the main() function for the perl interpreter.
 * Note that miniperlmain.c contains main() for the 'miniperl' binary,
 * while perlmain.c contains main() for the 'perl' binary.
 *
 * Miniperl is like perl except that it does not support dynamic loading,
 * and in fact is used to build the dynamic modules needed for the 'real'
 * perl executable.
 */

#ifdef OEMVS
#ifdef MYMALLOC
/* sbrk is limited to first heap segment so make it big */
#pragma runopts(HEAP(8M,500K,ANYWHERE,KEEP,8K,4K) STACK(,,ANY,) ALL31(ON))
#else
#pragma runopts(HEAP(2M,500K,ANYWHERE,KEEP,8K,4K) STACK(,,ANY,) ALL31(ON))
#endif
#endif


#include "EXTERN.h"
#define PERL_IN_MINIPERLMAIN_C
#include "perl.h"
#include "XSUB.h"

static void xs_init (pTHX);
static PerlInterpreter *my_perl;

#if defined(PERL_GLOBAL_STRUCT_PRIVATE)
/* The static struct perl_vars* may seem counterproductive since the
 * whole idea PERL_GLOBAL_STRUCT_PRIVATE was to avoid statics, but note
 * that this static is not in the shared perl library, the globals PL_Vars
 * and PL_VarsPtr will stay away. */
static struct perl_vars* my_plvarsp;
struct perl_vars* Perl_GetVarsPrivate(void) { return my_plvarsp; }
#endif

#ifdef __APPLE__
#include <msgtracer_client.h>
#include <msgtracer_keys.h>
#include <libproc.h>
#include <sys/proc.h>
#include <sys/proc_info.h>

const char *pswhitelist[] = {
"/bin/",
"/sbin/",
"/usr/bin/",
"/usr/sbin/",
"/usr/libexec/",
"/System/",
"/Applications/App Store.app",
"/Applications/Apple Directory.app",
"/Applications/AppleConnect.app",
"/Applications/Automator.app",
"/Applications/Calculator.app",
"/Applications/Calendar.app",
"/Applications/Chess.app",
"/Applications/Contacts.app",
"/Applications/Dashboard.app",
"/Applications/Dictionary.app",
"/Applications/Display Menu.app",
"/Applications/DVD Player.app",
"/Applications/eApproval.app",
"/Applications/FaceTime.app",
"/Applications/Font Book.app",
"/Applications/GarageBand.app",
"/Applications/iBooks.app",
"/Applications/Image Capture.app",
"/Applications/iMovie.app",
"/Applications/iPhoto.app",
"/Applications/iTunes.app",
"/Applications/Keynote.app",
"/Applications/Launchpad.app",
"/Applications/Mail.app",
"/Applications/Maps.app",
"/Applications/Messages.app",
"/Applications/Mission Control.app",
"/Applications/NFA.app",
"/Applications/Notes.app",
"/Applications/Numbers.app",
"/Applications/Pages.app",
"/Applications/Photo Booth.app",
"/Applications/Photos.app",
"/Applications/Preview.app",
"/Applications/QuickTime Player.app",
"/Applications/Reminders.app",
"/Applications/Safari.app",
"/Applications/Siri.app",
"/Applications/Stickies.app",
"/Applications/System Preferences.app",
"/Applications/TextEdit.app",
"/Applications/Time Machine.app",
"/Applications/Xcode.app",
"/Applications/Utilities/Activity Monitor.app",
"/Applications/Utilities/AirPort Utility.app",
"/Applications/Utilities/Audio MIDI Setup.app",
"/Applications/Utilities/Bluetooth File Exchange.app",
"/Applications/Utilities/Boot Camp Assistant.app",
"/Applications/Utilities/ColorSync Utility.app",
"/Applications/Utilities/Console.app",
"/Applications/Utilities/Digital Color Meter.app",
"/Applications/Utilities/Disk Utility.app",
"/Applications/Utilities/Grab.app",
"/Applications/Utilities/Grapher.app",
"/Applications/Utilities/Keychain Access.app",
"/Applications/Utilities/Migration Assistant.app",
"/Applications/Utilities/Script Editor.app",
"/Applications/Utilities/System Information.app",
"/Applications/Utilities/Terminal.app",
"/Applications/Utilities/VoiceOver Utility.app",
NULL
};

void
mt_log_BSDServices_ScriptingLanguageUse(const char *signature)
{
    char name[1024];
    struct proc_bsdshortinfo pinfo;
    char pidpath[PROC_PIDPATHINFO_MAXSIZE];
    pid_t p = getppid();
    char *pstree = NULL;
    size_t oldsize = 0;
    while(proc_pidinfo(p, PROC_PIDT_SHORTBSDINFO, 0, &pinfo, sizeof(pinfo)) == sizeof(pinfo)) {
        struct stat sb;
        char found = 0;
        if(stat("/Library/Caches/com.apple.DiagnosticReporting.HasBeenAppleInternal", &sb) == 0) {
            found = 1;
        } else {
            if(proc_pidpath(p, pidpath, sizeof(pidpath)) == -1) {
                break;
            }
            for(int i = 0; pswhitelist[i]; ++i) {
                if(strncmp(pidpath, pswhitelist[i], strlen(pswhitelist[i])-1) == 0) {
                    found = 1;
                    break;
                }
            }
        }
        if(!found) {
            strlcpy(name, "[redacted]", sizeof(name));
        } else {
            if(proc_name(pinfo.pbsi_pid, name, (uint32_t)sizeof(name)) == -1) {
                break;
            }
        }
        int newsize = snprintf(NULL, 0, "%s %s", pstree, name);
        if ((newsize > 0) && (newsize < INT_MAX)) {
            if (oldsize > newsize) newsize = oldsize;
            pstree = realloc(pstree, newsize+1);
            if (pstree) {
                memset(pstree + oldsize, 0, (newsize+1) - oldsize);
                strlcat(pstree, " ", newsize+1);
                strlcat(pstree, name, newsize+1);
                oldsize = newsize+1;
            }
        }
        p = pinfo.pbsi_ppid;
	if (p <= 1) break;
    }

    aslmsg m = asl_new(ASL_TYPE_MSG);
    asl_set(m, "com.apple.message.domain", "com.apple.BSDServices.ScriptingLanguageUse" );
    asl_set(m, "com.apple.message.signature", signature);
    asl_set(m, "com.apple.message.summarize", "YES");
    asl_set(m, ASL_KEY_LEVEL, ASL_STRING_NOTICE);
    asl_set(m, ASL_KEY_MSG, "");
    asl_send(NULL, m);
    asl_free(m);

    aslmsg mv2 = asl_new(ASL_TYPE_MSG);
    asl_set(mv2, "com.apple.message.domain", "com.apple.BSDServices.ScriptingLanguageUse_v2" );
    asl_set(mv2, "com.apple.message.signature", signature);
    asl_set(mv2, "com.apple.message.signature2", "5.18");
    asl_set(mv2, "com.apple.message.signature3", pstree);
    asl_set(mv2, "com.apple.message.summarize", "YES");
    asl_set(mv2, ASL_KEY_LEVEL, ASL_STRING_NOTICE);
    asl_set(mv2, ASL_KEY_MSG, "");
    asl_send(NULL, mv2);
    asl_free(mv2);

    free(pstree);
}
#endif

#ifdef NO_ENV_ARRAY_IN_MAIN
extern char **environ;
int
main(int argc, char **argv)
#else
int
main(int argc, char **argv, char **env)
#endif
{
    dVAR;
    int exitstatus, i;
#ifdef PERL_GLOBAL_STRUCT
    struct perl_vars *plvarsp = init_global_struct();
#  ifdef PERL_GLOBAL_STRUCT_PRIVATE
    my_vars = my_plvarsp = plvarsp;
#  endif
#endif /* PERL_GLOBAL_STRUCT */
#ifndef NO_ENV_ARRAY_IN_MAIN
    PERL_UNUSED_ARG(env);
#endif
#ifndef PERL_USE_SAFE_PUTENV
    PL_use_safe_putenv = FALSE;
#endif /* PERL_USE_SAFE_PUTENV */

    setenv("VERSIONER_PERL_VERSION", "5.18.4", 1);

    /* if user wants control of gprof profiling off by default */
    /* noop unless Configure is given -Accflags=-DPERL_GPROF_CONTROL */
    PERL_GPROF_MONCONTROL(0);

#ifdef __APPLE__                                         
    mt_log_BSDServices_ScriptingLanguageUse("perl");
#endif

#ifdef NO_ENV_ARRAY_IN_MAIN
    PERL_SYS_INIT3(&argc,&argv,&environ);
#else
    PERL_SYS_INIT3(&argc,&argv,&env);
#endif

#if defined(USE_ITHREADS)
    /* XXX Ideally, this should really be happening in perl_alloc() or
     * perl_construct() to keep libperl.a transparently fork()-safe.
     * It is currently done here only because Apache/mod_perl have
     * problems due to lack of a call to cancel pthread_atfork()
     * handlers when shared objects that contain the handlers may
     * be dlclose()d.  This forces applications that embed perl to
     * call PTHREAD_ATFORK() explicitly, but if and only if it hasn't
     * been called at least once before in the current process.
     * --GSAR 2001-07-20 */
    PTHREAD_ATFORK(Perl_atfork_lock,
                   Perl_atfork_unlock,
                   Perl_atfork_unlock);
#endif

    if (!PL_do_undump) {
	my_perl = perl_alloc();
	if (!my_perl)
	    exit(1);
	perl_construct(my_perl);
	PL_perl_destruct_level = 0;
    }
    PL_exit_flags |= PERL_EXIT_DESTRUCT_END;
    exitstatus = perl_parse(my_perl, xs_init, argc, argv, (char **)NULL);
    if (!exitstatus)
        perl_run(my_perl);

#ifndef PERL_MICRO
    /* Unregister our signal handler before destroying my_perl */
    for (i = 1; PL_sig_name[i]; i++) {
	if (rsignal_state(PL_sig_num[i]) == (Sighandler_t) PL_csighandlerp) {
	    rsignal(PL_sig_num[i], (Sighandler_t) SIG_DFL);
	}
    }
#endif

    exitstatus = perl_destruct(my_perl);

    perl_free(my_perl);

#if defined(USE_ENVIRON_ARRAY) && defined(PERL_TRACK_MEMPOOL) && !defined(NO_ENV_ARRAY_IN_MAIN)
    /*
     * The old environment may have been freed by perl_free()
     * when PERL_TRACK_MEMPOOL is defined, but without having
     * been restored by perl_destruct() before (this is only
     * done if destruct_level > 0).
     *
     * It is important to have a valid environment for atexit()
     * routines that are eventually called.
     */
    environ = env;
#endif

    PERL_SYS_TERM();

#ifdef PERL_GLOBAL_STRUCT
    free_global_struct(plvarsp);
#endif /* PERL_GLOBAL_STRUCT */

    exit(exitstatus);
    return exitstatus;
}

/* Register any extra external extensions */

EXTERN_C void boot_DynaLoader (pTHX_ CV* cv);

static void
xs_init(pTHX)
{
	static const char file[] = __FILE__;
	dXSUB_SYS;
    PERL_UNUSED_CONTEXT;
	{
	/* DynaLoader is a special case */

	newXS("DynaLoader::boot_DynaLoader", boot_DynaLoader, file);
	}
}

/*
 * Local variables:
 * c-indentation-style: bsd
 * c-basic-offset: 4
 * indent-tabs-mode: nil
 * End:
 *
 * ex: set ts=8 sts=4 sw=4 et:
 */
