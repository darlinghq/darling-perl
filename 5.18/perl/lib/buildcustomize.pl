#!perl

# We are miniperl, building extensions
# Reset @INC completely, adding the directories we need, and removing the
# installed directories (which we don't need to read, and may confuse us)
@INC = (q /Users/ariel/git/darling/src/external/perl/5.18/perl/cpan/AutoLoader/lib ,
        q /Users/ariel/git/darling/src/external/perl/5.18/perl/dist/Carp/lib ,
        q /Users/ariel/git/darling/src/external/perl/5.18/perl/dist/Cwd ,
        q /Users/ariel/git/darling/src/external/perl/5.18/perl/dist/Cwd/lib ,
        q /Users/ariel/git/darling/src/external/perl/5.18/perl/dist/ExtUtils-Command/lib ,
        q /Users/ariel/git/darling/src/external/perl/5.18/perl/dist/ExtUtils-Install/lib ,
        q /Users/ariel/git/darling/src/external/perl/5.18/perl/cpan/ExtUtils-MakeMaker/lib ,
        q /Users/ariel/git/darling/src/external/perl/5.18/perl/dist/ExtUtils-Manifest/lib ,
        q /Users/ariel/git/darling/src/external/perl/5.18/perl/cpan/File-Path/lib ,
        q /Users/ariel/git/darling/src/external/perl/5.18/perl/ext/re ,
        q /Users/ariel/git/darling/src/external/perl/5.18/perl/dist/Term-ReadLine/lib ,
        q /Users/ariel/git/darling/src/external/perl/5.18/perl/lib ,
        q . );
