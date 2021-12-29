#pragma once

/*AIUEO*/
const wchar_t hiragana[] = {
	L'あ', L'い', L'う', L'え', L'お', /* 0 */
	L'か', L'き', L'く', L'け', L'こ', /* K */
	L'が', L'ぎ', L'ぐ', L'げ', L'ご', /* G */
	L'さ', L'し', L'す', L'せ', L'そ', /* S */
	L'ざ', L'じ', L'ず', L'ぜ', L'ぞ', /* Z */
	L'た', L'ち', L'つ', L'て', L'と', /* T */
	L'だ', L'ぢ', L'づ', L'で', L'ど', /* D */
	L'な', L'に', L'ぬ', L'ね', L'の', /* N */
	L'は', L'ひ', L'ふ', L'へ', L'ほ', /* H */
	L'ば', L'び', L'ぶ', L'べ', L'ぼ', /* B */
	L'ぱ', L'ぴ', L'ぷ', L'ぺ', L'ぽ', /* P */
	L'ま', L'み', L'む', L'め', L'も', /* M */
	L'や', L'ゆ', L'よ',				  /* Y */
	L'ら', L'り', L'る', L'れ', L'ろ', /* R */
	L'わ', L'を',					  /* W */
	L'ん' /* Just 'N' */
};

const wchar_t katakana[] = {
	L'ア', L'イ', L'ウ', L'エ', L'オ', /* 0 */
	L'カ', L'キ', L'ク', L'ケ', L'コ', /* K */
	L'ガ', L'ギ', L'グ', L'ゲ', L'ゴ', /* G */
	L'サ', L'シ', L'ス', L'セ', L'ソ', /* S */
	L'ザ', L'ジ', L'ズ', L'ゼ', L'ゾ', /* Z */
	L'タ', L'チ', L'ツ', L'テ', L'ト', /* T */
	L'ダ', L'ヂ', L'ヅ', L'デ', L'ド', /* D */
	L'ナ', L'ニ', L'ヌ', L'ネ', L'ノ', /* N */
	L'ハ', L'ヒ', L'フ', L'ヘ', L'ホ', /* H */
	L'バ', L'ビ', L'ブ', L'ベ', L'ボ', /* B */
	L'パ', L'ピ', L'プ', L'ペ', L'ポ', /* P */
	L'マ', L'ミ', L'ム', L'メ', L'モ', /* M */
	L'ヤ', L'ユ', L'ヨ',				  /* Y */
	L'ラ', L'リ', L'ル', L'レ', L'ロ', /* R */
	L'ワ', L'ヲ',					  /* W */
	L'ン' /* Just 'N' */
};

const wchar_t* ENG[] = {
	L"a", L"i", L"u", L"e", L"o",
	L"ka", L"ki", L"ku", L"ke", L"ko",
	L"ga", L"gi", L"gu", L"ge", L"go",
	L"sa", L"shi", L"su", L"se", L"so",
	L"za", L"ji", L"zu", L"ze", L"zo",
	L"ta", L"chi", L"tsu", L"te", L"to",
	L"da", L"di", L"zu", L"de", L"do",
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

/* Maybe some Russian Weebs will have a use for this.				 *
 * I do know a few people who are native russians who could use this */

const wchar_t* РУС[] = {
	L"а", L"и", L"у", L"е", L"о",
	L"ка", L"ки", L"ку", L"ке", L"ко",
	L"га", L"ги", L"гу", L"ге", L"го",
	L"са", L"си", L"су", L"се", L"со",
	L"за", L"зи", L"зу", L"зе", L"зо",
	L"та", L"чи", L"тсу", L"те", L"то",
	L"да", L"ди", L"ду", L"де", L"до",
	L"на", L"ни", L"ну", L"не", L"но",
	L"ха", L"хи", L"ху", L"хе", L"хо",
	L"ба", L"би", L"бу", L"бе", L"бо",
	L"па", L"пи", L"пу", L"пе", L"по",
	L"ма", L"ми", L"му", L"ме", L"мо",
	L"я", L"ю", L"ё",
	L"ра", L"ри", L"ру", L"ре", L"ро",
	L"я", L"ё", /* There is no W sound in RU Cyrillic, not sure of UR *
				* it is ambiguous, either ва или уа is suitable	      */
	L"н",
};

enum alphabets
{
	both,
	hiragan,
	katakan,
};

// size_t err[71][2];
