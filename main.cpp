#include <fcntl.h>
#include <io.h>
#include <stdio.h>
#include <time.h>
#include <Windows.h>
#include <iostream>
#include <algorithm>
#include <string>

#include "tables.h"
#include "usage.h"


void transliterate(std::wstring buffer, std::wstring& output) 
{
	char flag = 1;
	for (int i = 0; i < buffer.size(); i++) {
		for (int j = 0; j < 71; j++) {
			if (buffer[i] == hiragana[j] || output[i] == katakana[j]) {
				output += ENG[j];
				flag = 0;
				break;
			}
			flag = 1;
		}
		if(flag)
			output += buffer[i];
	}
}

/*parse arguments given on the command line, setting vars passed in*/
void parseargs(int argc, char* argv[], int &trlt, int &forceaccuracy,
	int &cheat, int &al, unsigned short &qasked) {
	for (unsigned short i = 1; i < argc; i += 2) {
		if (!strcmp(argv[i], "-t")) {
			trlt = 1;
			break;
		}
		else if (!strcmp(argv[i], "-fa")) {
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
			printf(usage);
			exit(1);
		}
		else {
			printf("Issue parsing, see -h for usage");
			exit(1);
		}
	}
}

int main(int argc, char* argv[])
{
	unsigned short uiamount = 0,
	qasked = 15;
	int trlt = 0,
	forceaccuracy = 0,
	cheat = 0,
	al = both;

	parseargs(argc, argv, trlt, forceaccuracy, cheat, al, qasked);

	/*exit if an error is raised when setting cmd.exe to be unicode*/
	if (_setmode(_fileno(stdin), _O_U8TEXT) == -1 ||
		_setmode(_fileno(stdout), _O_U8TEXT) == -1)
		exit(1);

	if (!trlt) {
		/*set srand with time*/
		srand((unsigned int)time(NULL));
		/*set start time and set incorrect answers to 0*/
		ULONGLONG sttime = GetTickCount64();
		unsigned short inc = 0;

		int previndex = -1;
		/*loop for how many questions are desired to be asked */
		for (unsigned char i = 0; i < qasked; i++) {
			int index = 0;
			/* get a random number without any back to back repeats */
			do {
				index = rand() % (sizeof(hiragana) / sizeof(wchar_t));
			} while (index == previndex);
			/* set dispchar to the alphabet that as selected */
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
			/*get user input*/
			std::wstring buffer;
			std::getline(std::wcin, buffer);
			/*exit when input starts with !*/
			if (buffer[0] == L'!')
				break;

			uiamount++;
			/*make input lowercase*/
			std::transform(buffer.begin(), buffer.end(),
				buffer.begin(), ::tolower);
			/*behaviour when input isn't correct*/
			if (wcscmp(buffer.c_str(), ENG[index]) && 
				wcscmp(buffer.c_str(), РУС[index])) {
				//err[index][0]++;
				if (forceaccuracy) {
					goto input;
				}
				wprintf(L"it's %s | %s!\n", ENG[index], РУС[index]);
			} else {
				inc++;
			}
			previndex = index;
		}
		/*get time between starting and now*/
		ULONGLONG extime = GetTickCount64() - sttime;
		/* ensure that the person did enter something *
		 * otherwise we will have divisions by zero   */
		if (uiamount && inc) {
			/*calculate score*/
			float acc = ((float)inc / uiamount);
			/* score is the mean time (in ms) for an       *
			 * answer to be inputted, divided by accuracy, *
			 * and then divided by 10		       */
			int score = (int)((extime / uiamount) / acc) / 10;
			wprintf(L"Time (s): %llu\n"
				L"Mistakes: %u\n"
				L"Score:    %i\n",
				extime / 1000, uiamount - inc, score);
		} else {
			/*this is to avoid division by zero exceptions*/
			_putws(L"You failed to answer any question correctly\n");
			exit(0);
		}
	} else {
		/*transliterate*/
		/*set filepath to path of executable - the exe name + argv[2]*/
		std::string filepath = argv[0];
		filepath = filepath.substr(0, filepath.find_last_of('\\') + 1) 
			+ (argc > 2 ? argv[2] : "baka.txt");
		/*open file, if it fails fall to else*/
		FILE* fp;
		fopen_s(&fp, filepath.c_str(), "r,ccs=UTF-8");
		fwide(fp, 1);
		if (fp) {
			/*initialize input and output buffers*/
			wchar_t buffer[0xff];
			std::wstring output;
			/* transliterate every line in the file */
			while (fgetws(buffer, sizeof buffer / sizeof(wchar_t), fp))
				transliterate(buffer, output);
			/*print output and cleanup file*/
			_putws(output.c_str());
			fclose(fp);
		} else {
			std::wstring input, output;
			std::getline(std::wcin, input);
			transliterate((wchar_t*)input.c_str(), output);
			wprintf(L"%s\n", output.c_str());
		}
	}
}
