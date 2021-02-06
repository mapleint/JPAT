#pragma once

/*	A	   I	  U	    E	   O*/
const wchar_t hiragana[] = {
	L'��', L'��', L'��', L'��', L'��', /* 0 */
	L'��', L'��', L'��', L'��', L'��', /* K */
	L'��', L'��', L'��', L'��', L'��', /* G */
	L'��', L'��', L'��', L'��', L'��', /* S */
	L'��', L'��', L'��', L'��', L'��', /* Z */
	L'��', L'��', L'��', L'��', L'��', /* T */
	L'��', L'��', L'��', L'��', L'��', /* D */
	L'��', L'��', L'��', L'��', L'��', /* N */
	L'��', L'��', L'��', L'��', L'��', /* H */
	L'��', L'��', L'��', L'��', L'��', /* B */
	L'��', L'��', L'��', L'��', L'��', /* P */
	L'��', L'��', L'��', L'��', L'��', /* M */
	L'��', L'��', L'��',				  /* Y */
	L'��', L'��', L'��', L'��', L'��', /* R */
	L'��', L'��',					  /* W */
	L'��' /* Just 'N' */
};

const wchar_t katakana[] = {
	L'�A', L'�C', L'�E', L'�G', L'�I', /* 0 */
	L'�J', L'�L', L'�N', L'�P', L'�R', /* K */
	L'�K', L'�M', L'�O', L'�Q', L'�S', /* G */
	L'�T', L'�V', L'�X', L'�Z', L'�\', /* S */
	L'�U', L'�W', L'�Y', L'�[', L'�]', /* Z */
	L'�^', L'�`', L'�c', L'�e', L'�g', /* T */
	L'�_', L'�a', L'�d', L'�f', L'�h', /* D */
	L'�i', L'�j', L'�k', L'�l', L'�m', /* N */
	L'�n', L'�q', L'�t', L'�w', L'�z', /* H */
	L'�o', L'�r', L'�u', L'�x', L'�{', /* B */
	L'�p', L'�s', L'�v', L'�y', L'�|', /* P */
	L'�}', L'�~', L'��', L'��', L'��', /* M */
	L'��', L'��', L'��',				  /* Y */
	L'��', L'��', L'��', L'��', L'��', /* R */
	L'��', L'��',					  /* W */
	L'��' /* Just 'N' */
};

const wchar_t* ENG[] = {
	L"a", L"i", L"u", L"e", L"o",
	L"ka", L"ki", L"ku", L"ke", L"ko",
	L"ga", L"gi", L"gu", L"ge", L"go",
	L"sa", L"si", L"su", L"se", L"so",
	L"za", L"zi", L"zu", L"ze", L"zo",
	L"ta", L"chi", L"tsu", L"te", L"to",
	L"da", L"di", L"du", L"de", L"do",
	L"na", L"ni", L"nu", L"ne", L"no",
	L"ha", L"hi", L"hu", L"he", L"ho",
	L"ba", L"bi", L"bu", L"be", L"bo",
	L"pa", L"pi", L"pu", L"pe", L"po",
	L"ma", L"mi", L"mu", L"me", L"mo",
	L"ya", L"yu", L"yo",
	L"ra", L"ri", L"ru", L"re", L"ro",
	L"wa", L"wo",
	L"n",
};

enum alphabets
{
	both,
	hiragan,
	katakan,
};

size_t err[71][2];