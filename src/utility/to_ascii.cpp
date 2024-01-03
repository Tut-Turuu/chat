
namespace ut {

    char key_code_to_ascii(int code, bool is_cap) {
        char letter;
        if (code >= 0 && code <= 25) {
            letter = code + (is_cap ? 65 : 97);
        } else if (code >= 26 && code <= 35) {
            if (is_cap) {
                if (code == 26) {
                    letter = 41;
                } else if (code == 27) {
                    letter = 33;
                } else if (code == 28) {
                    letter = 64;
                } else if (code >= 29 && code <= 31) {
                    letter = code + 6;
                } else if (code == 32) {
                    letter = 94;
                } else if (code == 33) {
                    letter = 38;
                } else if (code == 34) {
                    letter = 42;
                } else if (code == 35) {
                    letter = 40;
                }
            } else {
                letter = code + 22;
            }
        } else if (code == 56) {
            letter = (is_cap ? 95 : 45);
        } else if (code == 55) {
            letter = (is_cap ? 43 : 61);
        } else if (code == 49) {
            letter = (is_cap ? 60 : 44);
        } else if (code == 50) {
            letter = (is_cap ? 62 : 46);
        } else if (code == 51) {
            letter = (is_cap ? 34 : 39);
        } else if (code == 48) {
            letter = (is_cap ? 58 : 59);
        } else if (code == 46) {
            letter = (is_cap ? 123 : 91);
        } else if (code == 47) {
            letter = (is_cap ? 125 : 93);
        } else if (code == 53) {
            letter = (is_cap ? 124 : 92);
        } else if (code == 52) {
            letter = (is_cap ? 63 : 47);
        } else if (code == 54) { 
            letter = (is_cap ? 126 : 96);
        } else if (code == 57) {
            letter = 32;
        }
        return letter;
    }
}
