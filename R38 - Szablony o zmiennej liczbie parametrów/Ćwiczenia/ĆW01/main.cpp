



template <typename ... Args> //pakiet parametrów szablony
void funkcja(Args ... args); //pakiet argumentów szablony


/*
 * Wielokropek w ostrym nawiaseie oznacz, że to, co następuje po nim , jest pakietem parametrów.
 * To, co następuje przed nim , określa jaki to rodzaj pakietu. W naszym przypadku jest tu słowo typename co oznacza, że chodzi o pakiet parametrów będących typami
 * Wielokropek w okrągłym nawiasie  - oznacza, że tu kompilator ma postawić rozwiniętą postać pakietu.
 */