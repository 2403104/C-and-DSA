/**
 * Difference between regex_search and regex_match:
 * - regex_match: This function only returns true if the entire input sequence matches the regular expression.
 * - regex_search: This function returns true if any part of the input sequence matches the regular expression.
 */
# include <iostream>
# include <algorithm>
# include <vector>
# include <string>
# include <regex>
using namespace std;


int main(){

    string s;
    while(true){
        cin>>s;
        // regex e("abc");//matches exact match
        // regex e("abc",regex_constants::icase);//case insensitive
        // regex e("abc.",regex_constants::icase);// dot will match anything after word except new line
        // regex e("abc?"); // ? means zero or one preceding character if(word is ab or abc will be matched)
        // regex e("ankit*");//zero or more last char (like ankittt ankitt anki)
        // regex e("ankit+");//one or more last char (like ankittt ankitt anki)
        // regex e("ab[cd]") ; //matches either c or d but not both
        // regex e("ab[cd]*") ; //zero or more any thing inside []
        // regex e("ab[^cd]*");//any char not inside the [](every thing will match unless any c or d is present )
        // regex e("ab[cd]{3}");//exact 3 match  any combination from bracket
        // regex e("ab[cd]{3,}");// 3 or more match  any combination from bracket
        // regex e("ab[cd]{3,5}");// either 3 or 4 or 5 more match  any combination from bracket
        // regex e("abc|de[fg]");//either abc or def/deg
        // regex e("abc(d|e|f)");// will match only if either from parenthesis is present
        // regex e("(abc)de+\\1");// will match (subgrp)de(subgrp) 1 is for first group
        // regex e("(ab)c(de+)\\2\\1");//no of e should be same at all the place where it is used
        // regex e("[[:w:]]+@[[:w:]]+\\.com");//[[:w:]] one or more word char : digit, number , underscore


        // bool match=regex_match(s,e);

        // regex e("^abc");//will match only at the beginning
        // regex e("abc$");//will match only at the end
        regex e("");
        bool match=regex_search(s,e);
        if(match) cout<<"Matched"<<endl;
        else cout<<"Not matched"<<endl;
    }

    return 0;
}

