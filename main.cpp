#include <fcntl.h>
#include <io.h>
#include <stdio.h>
#include <time.h>
#include <Windows.h>
#include <iostream>
#include <algorithm>
#include <string>

#include "tables.h"

unsigned short uiamount = 0;
unsigned short qasked = 15;

int main(int argc, char* argv[])
{
	int forceaccuracy = 0;
	int cheat = 0;
	int al = both;
	for (unsigned short i = 1; i < argc; i += 2) {
		if (!strcmp(argv[i], "-fa")) {
			forceaccuracy = std::stoi(argv[i + 1]);
		}
		else if (!strcmp(argv[i], "-l")) {
			cheat = std::stoi(argv[i + 1]);
		}
		else if (!strcmp(argv[i], "-a")) {
			switch (argv[i][0]) {
			case 'h':
				al = hiragan;
				break;
			case 'k':
				al = katakan;
				break;
			case 'b':
				al = both;
				break;
			}
		}
		else if (!strcmp(argv[i], "-q")) {
			qasked = std::stoi(argv[i + 1]);
		}
		else if (!strcmp(argv[i], "-h")) {
			printf( "JPAT, JaPanese Alphabet Trainer -h\n\n"
					"USAGE: JPAT [options]\n"
					"Options:\n"
					"\t-fa force accuracy, the following arg is a int value determining this parameter. default: 0\n"
					"\t-l learn mode, tells you the answers, the following arg is an int value determining this parameter. default: 0\n"
					"\t-a Alphabet Selection, the following arg is a char, \n"
					"\t\t'k' for katakana, 'h' for hiragana, and 'b' for both randomly switching. default: b\n"
					"\t-q question amount, as an integer, default: 15\n\n"
					"for bug reporting, suggestions, and marriage proposals (JP women only) please contact mapelint@protonmail.com\n");
			return 0;
		} else {
			printf("Issue parsing, see -h for usage");
			return 1;
		}
	}
	srand((unsigned int)time(NULL));
	int ploc = _setmode(_fileno(stdout), _O_U16TEXT);

	ULONGLONG sttime;
	sttime = GetTickCount64();
	unsigned short inc = 0;

	int previndex = -1;
	for (unsigned char i = 0; i < qasked; i++) {
		std::wstring buffer;
		int index = 0;
		do {
			index = rand() % (sizeof(hiragana) / sizeof(wchar_t));
		}
		while (index == previndex);

		wchar_t dispchar = L' ';

		switch (al) {
		case both:
			if (!(rand() % 2))
				dispchar = hiragana[index];
			else
				dispchar = katakana[index];
			break;
		case katakan:
			dispchar = katakana[index];
			break;
		case hiragan:
			dispchar = hiragana[index];
			break;
		}

		putwchar(hiragana[index]);
			wprintf(L" %s\n", cheat ? ENG[index] : L"");

	input:

		std::getline(std::wcin, buffer);
		if (buffer[0] == L'!')
			break;

		uiamount++;

		std::transform(buffer.begin(), buffer.end(), buffer.begin(), ::tolower);

		if (wcscmp(buffer.c_str(), ENG[index])) {
			err[index][0]++;
			if (forceaccuracy) {
				goto input;
			}
			wprintf(L"it's %s!\n", ENG[index]);
		} else {
			inc++;
		}
		previndex = index;
	}
	ULONGLONG extime = GetTickCount64() - sttime;
	if (uiamount && inc) {
		long double acc = ((long double)inc / uiamount);
		int score = (int)((extime / uiamount) / acc) / 10;
		wprintf(L"\nIt took you %llus to complete the test, and made %u mistakes,\n"
			L"your score is %i (lower is better)\n",
			extime / 1000, uiamount - inc, score);
	} else { 
		wprintf(L"You failed to answer any question correctly\n");
	}
}
