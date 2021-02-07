# JPAT - JaPanese Alphabet Trainer

The JaPanese Alphabet trainer is a C++ Windows CLI tool for learning the Japanese Hiragana and Katakana Alphabets from the Russian or English Alphabets, it also supports  Japanese to English transliteration

## Linux Compatible ANSI C version
A linux compatible version of this software written in ANSI C can be found [here](

## Compilation
This was compiled under the MSVC compiler with MSVS 2019, I can't guarantee anything else will work.
## Setup
Go to your windows CMD and make sure that your codepage is UTF8 compliant and you have a font that can display Japanese and Russian

## Usage

```python
JPAT, JaPanese Alphabet Trainer -h
USAGE: JPAT [options]
Options:
    -t JP to ENG 'Transliterator', it is mutually exclusive to all other arguments.
        The argument following this will be the FILE to be transliterated, if this isn't present, it will take input from the user at runtime
    -fa force accuracy, the following arg is a int value determining this parameter. default: 
    -l learn mode, tells you the answers, the following arg is an int value determining this parameter. default: 0
    -a Alphabet Selection, the following arg is a char
        'k' for katakana, 'h' for hiragana, and 'b' for both randomly switching. default: b
    -q question amount, as an integer, default: 15

for bug reporting, suggestions, and marriage proposals (JP women) please contact mapelint@protonmail.com
```

## Contributing
if you can tolerate my programming style, you are more than welcome to contribute, open a pull request!



## License
[WTFPL](http://www.wtfpl.net/txt/copying/)
