/*
 * Copyright (c) 2021, Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "count-unique-characters-of-all-substrings-of-a-given-string.cpp"

using namespace std;

TEST(CountUniqueCharactersOfAllSubstringsOfAGivenString, ABC) {
  EXPECT_EQ(10, Solution().uniqueLetterString("ABC"));
}

TEST(CountUniqueCharactersOfAllSubstringsOfAGivenString, ABA) {
  EXPECT_EQ(8, Solution().uniqueLetterString("ABA"));
}

TEST(CountUniqueCharactersOfAllSubstringsOfAGivenString, LEETCODE) {
  EXPECT_EQ(92, Solution().uniqueLetterString("LEETCODE"));
}

TEST(
    CountUniqueCharactersOfAllSubstringsOfAGivenString,
    DELQGVWNZKIJJPSXOVWWIZUXCEGWSQLESNSRBMKZARFPAXSVWQEZDENDAHNNIBHGHTFDLPGDLFXMIYRFNLMXHNPIFUAXINXPXLCTTJNLGGMKJIOEWBECNOFQPVCIKIAZMNGHEHFMCPWSMJTMGVSXTOGCGUYKFMNCGLCBRAFJLJVPIVDOLJBURULPGXBVDCEWXXXLTRMSHPKSPFDGNVOCZWDXJUWVNAREDOKTZMIUDKDQWWWSAEUUDBHMWZELOSBIHMAYJEMGZPMDOOGSCKLVHTGMETHUISCLJKDOQEWGVBULEMUXGTRKGXYFDIZTZWMLOFTCANBGUARNWQEQWGMIKMORVQUZANJNRNPMJWYLVHWKDFLDDBBMILAKGFROEQAMEVONUVHOHGPKLBPNYZFPLXNBCIFENCGIMIDCXIIQJWPVVCOCJTSKSHVMQJNLHSQTEZQTTMOXUSKBMUJEJDBJQNXECJGSZUDENJCPTTSREKHPRIISXMWBUGMTOVOTRKQCFSDOTEFPSVQINYLHXYVZTVAMWGPNKIDLOPGAMWSKDXEPLPPTKUHEKBQAWEBMORRZHBLOGIYLTPMUVBPGOOOIEBJEGTKQKOUURHSEJCMWMGHXYIAOGKJXFAMRLGTPNSLERNOHSDFSSFASUJTFHBDMGBQOKZRBRAZEQQVWFRNUNHBGKRFNBETEDJIWCTUBJDPFRRVNZENGRANELPHSDJLKVHWXAXUTMPWHUQPLTLYQAATEFXHZARFAUDLIUDEHEGGNIYICVARQNRJJKQSLXKZZTFPVJMOXADCIGKUXCVMLPFJGVXMMBEKQXFNXNUWOHCSZSEZWZHDCXPGLROYPMUOBDFLQMTTERGSSGVGOURDWDSEXONCKWHDUOVDHDESNINELLCTURJHGCJWVIPNSISHRWTFSFNRAHJAJNNXKKEMESDWGIYIQQRLUUADAXOUEYURQRVZBCSHXXFLYWFHDZKPHAGYOCTYGZNPALAUZSTOU) {
  EXPECT_EQ(
      629134,
      Solution().uniqueLetterString(
          "DELQGVWNZKIJJPSXOVWWIZUXCEGWSQLESNSRBMKZARFPAXSVWQEZDENDAHNNIBHGHTFD"
          "LPGDLFXMIYRFNLMXHNPIFUAXINXPXLCTTJNLGGMKJIOEWBECNOFQPVCIKIAZMNGHEHFM"
          "CPWSMJTMGVSXTOGCGUYKFMNCGLCBRAFJLJVPIVDOLJBURULPGXBVDCEWXXXLTRMSHPKS"
          "PFDGNVOCZWDXJUWVNAREDOKTZMIUDKDQWWWSAEUUDBHMWZELOSBIHMAYJEMGZPMDOOGS"
          "CKLVHTGMETHUISCLJKDOQEWGVBULEMUXGTRKGXYFDIZTZWMLOFTCANBGUARNWQEQWGMI"
          "KMORVQUZANJNRNPMJWYLVHWKDFLDDBBMILAKGFROEQAMEVONUVHOHGPKLBPNYZFPLXNB"
          "CIFENCGIMIDCXIIQJWPVVCOCJTSKSHVMQJNLHSQTEZQTTMOXUSKBMUJEJDBJQNXECJGS"
          "ZUDENJCPTTSREKHPRIISXMWBUGMTOVOTRKQCFSDOTEFPSVQINYLHXYVZTVAMWGPNKIDL"
          "OPGAMWSKDXEPLPPTKUHEKBQAWEBMORRZHBLOGIYLTPMUVBPGOOOIEBJEGTKQKOUURHSE"
          "JCMWMGHXYIAOGKJXFAMRLGTPNSLERNOHSDFSSFASUJTFHBDMGBQOKZRBRAZEQQVWFRNU"
          "NHBGKRFNBETEDJIWCTUBJDPFRRVNZENGRANELPHSDJLKVHWXAXUTMPWHUQPLTLYQAATE"
          "FXHZARFAUDLIUDEHEGGNIYICVARQNRJJKQSLXKZZTFPVJMOXADCIGKUXCVMLPFJGVXMM"
          "BEKQXFNXNUWOHCSZSEZWZHDCXPGLROYPMUOBDFLQMTTERGSSGVGOURDWDSEXONCKWHDU"
          "OVDHDESNINELLCTURJHGCJWVIPNSISHRWTFSFNRAHJAJNNXKKEMESDWGIYIQQRLUUADA"
          "XOUEYURQRVZBCSHXXFLYWFHDZKPHAGYOCTYGZNPALAUZSTOU"));
}

TEST(
    CountUniqueCharactersOfAllSubstringsOfAGivenString,
    HJPNWLSNXDDEHVXKROILVYDDKFRFSKHKZCNJTKGHSSZOFUXNNJOYGHBNLICUNQRPPKBWWYZOZJXBZTJSXQXMZWARKJQWPVBUWCYGPNEQTHATPLQROFQGWWFMHZXJDDHYUPNLUZKKYSOFGQAWJYRWHFGDPKHIQGKPUPGDEONIPVPTKFQLUYTOGOLJIAEXRNXCKEOFQOJLTDJUUJCNJDJOHQBRZZZZNYMYRBBCJJMACDQYHPWTCMMLPJBQICTCVJGSWQYQCJCRIBFMYAJSODSQICWALLSZOQKXJSOSKXXSTDEAVAVNQNRJELSXXLERMAXMLGQAAEUVNEOVUMNEAZAEGTLZTLXHIHPQBAJJWJUJYORHLDXXBDOCKLRKLGVNOUBEGJRFRSCIGSEMPORRJKIYNCUGKKSEDFPUIQZBMWDAAGQLXIVXAWCCAVCRTELSCBEWRQAXVHKNXPYZDZJUHVOIZXKCXUXLLBKYYYGTQDNGPFFVDVTIVNBNLSURZROXYXCEVSOJBHJHUJQXENHLVLGZCSIBCXWOMFPYEVUMLJANFPJPYHSQXXNAEWKNPNUHPEFFDVTYJQVVYZJEOCTIVQWANNXUBSLXNFIIJADMAMUAXYPNVXAFPLJKZNYSXMYVZNFHVJFDTNYKVXRPANVPVFEDXUPOTPVYQJDXOWYZUDQVVGWPKYJNQLHBVPLHVHPMHLDJWUKQRRDNMAZFRGNNRYNTMLLYSXQJIAPVPEKZCPAYIJAMUAKKBSLWGCTPBQFFYWUEMLURPAYKECSWBQFPFBZGPOPJEXEQSAVXOTTFINNTQJUTNZROGAUJKTLRSNHBEYIROTXSVLTJQJKBXRXQOMTAJOXYTVKQBZSDXANTFQHZSSTBFSONMVQRXPLGRQLTMNNLANAJVIVUCDROTUOSMECCVKIQYSSWGYTKGNHCCRZVLIEPVGWPZBNYYHEMUPZQGZTGHIOZTYAENJEFNZCOFUGSYQYPUOKXGLKCEQOTZWYY) {
  EXPECT_EQ(
      637068,
      Solution().uniqueLetterString(
          "HJPNWLSNXDDEHVXKROILVYDDKFRFSKHKZCNJTKGHSSZOFUXNNJOYGHBNLICUNQRPPKBW"
          "WYZOZJXBZTJSXQXMZWARKJQWPVBUWCYGPNEQTHATPLQROFQGWWFMHZXJDDHYUPNLUZKK"
          "YSOFGQAWJYRWHFGDPKHIQGKPUPGDEONIPVPTKFQLUYTOGOLJIAEXRNXCKEOFQOJLTDJU"
          "UJCNJDJOHQBRZZZZNYMYRBBCJJMACDQYHPWTCMMLPJBQICTCVJGSWQYQCJCRIBFMYAJS"
          "ODSQICWALLSZOQKXJSOSKXXSTDEAVAVNQNRJELSXXLERMAXMLGQAAEUVNEOVUMNEAZAE"
          "GTLZTLXHIHPQBAJJWJUJYORHLDXXBDOCKLRKLGVNOUBEGJRFRSCIGSEMPORRJKIYNCUG"
          "KKSEDFPUIQZBMWDAAGQLXIVXAWCCAVCRTELSCBEWRQAXVHKNXPYZDZJUHVOIZXKCXUXL"
          "LBKYYYGTQDNGPFFVDVTIVNBNLSURZROXYXCEVSOJBHJHUJQXENHLVLGZCSIBCXWOMFPY"
          "EVUMLJANFPJPYHSQXXNAEWKNPNUHPEFFDVTYJQVVYZJEOCTIVQWANNXUBSLXNFIIJADM"
          "AMUAXYPNVXAFPLJKZNYSXMYVZNFHVJFDTNYKVXRPANVPVFEDXUPOTPVYQJDXOWYZUDQV"
          "VGWPKYJNQLHBVPLHVHPMHLDJWUKQRRDNMAZFRGNNRYNTMLLYSXQJIAPVPEKZCPAYIJAM"
          "UAKKBSLWGCTPBQFFYWUEMLURPAYKECSWBQFPFBZGPOPJEXEQSAVXOTTFINNTQJUTNZRO"
          "GAUJKTLRSNHBEYIROTXSVLTJQJKBXRXQOMTAJOXYTVKQBZSDXANTFQHZSSTBFSONMVQR"
          "XPLGRQLTMNNLANAJVIVUCDROTUOSMECCVKIQYSSWGYTKGNHCCRZVLIEPVGWPZBNYYHEM"
          "UPZQGZTGHIOZTYAENJEFNZCOFUGSYQYPUOKXGLKCEQOTZWYY"));
}

TEST(
    CountUniqueCharactersOfAllSubstringsOfAGivenString,
    PNJBRGRPQSLSXPQBQKGGTUSHTKLLXHGXZBDMHNBZXKWZXTAANMHTOIRXHEYANOPLBVJROVZUDZNMETKKXRDMRHVMLDBHQTRIYGQFMBTZPPXGCLRJJYWHZZURDNTKWPNHLEJHFPPVQJAGSZCNUDMZWWCYUAQZGTUDMPJKLUQOSESLYGYWZKIXJQGHSOCVJQIGVXWQLOYUGFHCJSCJGHQMIGLGYAZWELSHZAPAEZQGMCMRMFRFZTTDGQUIZYDUCBVXZZUIDDCNWUAAPDUNZLBAGNIFNDBJYALQQGBRAMHBIVVERVXRTCSZSZWIGRLWZMUTEYSWZAGUDTPVLRJMOBUHOZBGHKHVOXAWCXMJNAZLQLKQQQNOCLUFGKOVBOKVKOEZEKNWHCFGCENVAABLPVTCEJVZNDTZNCRELHEDWLWIQGDBDGCTGUBZCZGTOVUFNCICJLWSMFDCRQEAGHUEVYEXQDHFFIKVECUAZRELOFJMYJJZNNJDKIMBKLRHSJUSBSTQHVLEJTJCCZQNZBVYFZXGAUDYOSCKYSMMINOANJMBAFHTNBRRZQAGLLWXLXMJANYFELMWRUFTLZUUHBSJEXOOBJKMYMLITIWJTDXSCOTZVZNVIXPDHNSXSODIEATIPIAODGCMDGYVZRJRVFCCMECCHXTIRAIQIJOWZWNRVRKOSIMQSDYRSCBONPPJTEYOEBNUOMRBIFRBQBTECLFQZTBBYROOMREHVFWTRVCODLLGJCTGUXEICJOUDMXBEVZRVRAVKIDNRICWSBNXMXVDCKZAHMQZBRLQUGTMJVOQBXARMLGJEQCORHNODVNOQFOMDPKRCOQOUDCPEOCHKHNHDGHBBYJIIYRVPKVSDYDIWOWCTGDZEHQAFDSZHJKTAYAYQCFVNAJQUQUQGFTPTRYAMLLXNSYSISFBEFNTDJWHZBWRVKRIHQXUOFBHRJKRIGJLDKRMUJQWAJGUFKSQEKMFAIJZSJIOTMCIVROAOEQPOIUD) {
  EXPECT_EQ(
      620286,
      Solution().uniqueLetterString(
          "PNJBRGRPQSLSXPQBQKGGTUSHTKLLXHGXZBDMHNBZXKWZXTAANMHTOIRXHEYANOPLBVJR"
          "OVZUDZNMETKKXRDMRHVMLDBHQTRIYGQFMBTZPPXGCLRJJYWHZZURDNTKWPNHLEJHFPPV"
          "QJAGSZCNUDMZWWCYUAQZGTUDMPJKLUQOSESLYGYWZKIXJQGHSOCVJQIGVXWQLOYUGFHC"
          "JSCJGHQMIGLGYAZWELSHZAPAEZQGMCMRMFRFZTTDGQUIZYDUCBVXZZUIDDCNWUAAPDUN"
          "ZLBAGNIFNDBJYALQQGBRAMHBIVVERVXRTCSZSZWIGRLWZMUTEYSWZAGUDTPVLRJMOBUH"
          "OZBGHKHVOXAWCXMJNAZLQLKQQQNOCLUFGKOVBOKVKOEZEKNWHCFGCENVAABLPVTCEJVZ"
          "NDTZNCRELHEDWLWIQGDBDGCTGUBZCZGTOVUFNCICJLWSMFDCRQEAGHUEVYEXQDHFFIKV"
          "ECUAZRELOFJMYJJZNNJDKIMBKLRHSJUSBSTQHVLEJTJCCZQNZBVYFZXGAUDYOSCKYSMM"
          "INOANJMBAFHTNBRRZQAGLLWXLXMJANYFELMWRUFTLZUUHBSJEXOOBJKMYMLITIWJTDXS"
          "COTZVZNVIXPDHNSXSODIEATIPIAODGCMDGYVZRJRVFCCMECCHXTIRAIQIJOWZWNRVRKO"
          "SIMQSDYRSCBONPPJTEYOEBNUOMRBIFRBQBTECLFQZTBBYROOMREHVFWTRVCODLLGJCTG"
          "UXEICJOUDMXBEVZRVRAVKIDNRICWSBNXMXVDCKZAHMQZBRLQUGTMJVOQBXARMLGJEQCO"
          "RHNODVNOQFOMDPKRCOQOUDCPEOCHKHNHDGHBBYJIIYRVPKVSDYDIWOWCTGDZEHQAFDSZ"
          "HJKTAYAYQCFVNAJQUQUQGFTPTRYAMLLXNSYSISFBEFNTDJWHZBWRVKRIHQXUOFBHRJKR"
          "IGJLDKRMUJQWAJGUFKSQEKMFAIJZSJIOTMCIVROAOEQPOIUD"));
}
