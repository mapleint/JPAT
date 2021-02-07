#pragma once
/* shove this ugly text in a coener :D*/
const char* usage =
"JPAT, JaPanese Alphabet Trainer -h\n\n"
"USAGE: JPAT [options]\n"
"-t JP to ENG \'Transliterator\', it is mutually exclusive to all other arguments,\n"
"\tThe argument following this will be the FILE to be transliterated, if this isn't present, it will take input from the user at runtime"
"Options:\n"
"\t-fa force accuracy, the following arg is a int value determining this parameter. default: 0\n"
"\t-l learn mode, tells you the answers, the following arg is an int value determining this parameter. default: 0\n"
"\t-a Alphabet Selection, the following arg is a char, \n"
"\t\t'k' for katakana, 'h' for hiragana, and 'b' for both randomly switching. default: b\n"
"\t\t'R' works for Russian Cyrillic, though it's to be noted that this is less accurate than the JP options"
"\t-q question amount, as an integer, default: 15\n\n"
"for bug reporting, suggestions, and marriage proposals (JP/RU women (opetional) only) please contact mapelint@protonmail.com\n";