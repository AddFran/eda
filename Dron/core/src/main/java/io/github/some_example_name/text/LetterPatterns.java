package io.github.some_example_name.text;

import java.util.HashMap;
import java.util.Map;

// Literalmente, todos los patrones de letras hechos a mano xd
public class LetterPatterns {
    // Crea un map asociando dos valores, el caracter (char) y su mapa o matriz
    private static final Map<Character, LetterPattern> patterns = new HashMap<>();

    // Cada uno de las letras
    static {
        // A
        patterns.put('A', new LetterPattern(new boolean[][]{
            {false, true, true, true, false},
            {true, false, false, false, true},
            {true, true,  true,  true,  true},
            {true, false, false, false, true},
            {true, false, false, false, true}
        }));
        // B
        patterns.put('B', new LetterPattern(new boolean[][]{
            {true, true, true, true, false},
            {true, false, false, false, true},
            {true, true,  true,  true,  true},
            {true, false, false, false, true},
            {true, true, true, true, false}
        }));
        // C
        patterns.put('C', new LetterPattern(new boolean[][]{
            {true, true, true, true, true},
            {true, false, false, false, false},
            {true, false,  false,  false,  false},
            {true, false, false, false, false},
            {true, true, true, true, true}
        }));
        // D
        patterns.put('D', new LetterPattern(new boolean[][]{
            {true, true, true, true, false},
            {true, false, false, false, true},
            {true, false,  false,  false,  true},
            {true, false, false, false, true},
            {true, true, true, true, false}
        }));
        // E
        patterns.put('E', new LetterPattern(new boolean[][]{
            {true, true, true, true, true},
            {true, false, false, false, false},
            {true, true,  true,  true,  true},
            {true, false, false, false, false},
            {true, true, true, true, true}
        }));
        // F
        patterns.put('F', new LetterPattern(new boolean[][]{
            {true, true, true, true, true},
            {true, false, false, false, false},
            {true, true,  true,  true,  false},
            {true, false, false, false, false},
            {true, false, false, false, false}
        }));
        // G
        patterns.put('G', new LetterPattern(new boolean[][]{
            {true, true, true, true, true},
            {true, false, false, false, false},
            {true, false,  true,  true,  true},
            {true, false, false, false, true},
            {true, true, true, true, true}
        }));
        // H
        patterns.put('H', new LetterPattern(new boolean[][]{
            {true, false, false, false, true},
            {true, false, false, false, true},
            {true, true,  true,  true,  true},
            {true, false, false, false, true},
            {true, false, false, false, true}
        }));
        // I
        patterns.put('I', new LetterPattern(new boolean[][]{
            {true, true, true, true, true},
            {false, false, true, false, false},
            {false, false, true,  false,  false},
            {false, false, true, false, false},
            {true, true, true, true, true}
        }));
        // j
        patterns.put('J', new LetterPattern(new boolean[][]{
            {true, true, true, true, true},
            {false, false, true, false, false},
            {false, false, true,  false,  false},
            {true, false, true, false, false},
            {true, true, true, false, false}
        }));
        // K
        patterns.put('K', new LetterPattern(new boolean[][]{
            {true, false, false, false, true},
            {true, false, false, true, false},
            {true, true, true,  false,  false},
            {true, false, false, true, false},
            {true, false, false, false, true}
        }));
        // L
        patterns.put('L', new LetterPattern(new boolean[][]{
            {true, false,  false,  false,  false},
            {true, false, false, false, false},
            {true, false, false,  false,  false},
            {true, false, false, false, false},
            {true, true, true, true, true}
        }));
        // M
        patterns.put('M', new LetterPattern(new boolean[][]{
            {true, false,  false,  false,  true},
            {true, true, false, true, true},
            {true, false, true,  false,  true},
            {true, false, false, false, true},
            {true, false, false, false, true}
        }));
        // N
        patterns.put('N', new LetterPattern(new boolean[][]{
            {true, false,  false,  false,  true},
            {true, true, false, false, true},
            {true, false, true,  false,  true},
            {true, false, false, true, true},
            {true, false, false, false, true}
        }));
        // Ñ
        patterns.put('Ñ', new LetterPattern(new boolean[][]{
            {false, true,  true,  true,  false},
            {true, true, false, false, true},
            {true, false, true,  false,  true},
            {true, false, false, true, true},
            {true, false, false, false, true}
        }));
        // O
        patterns.put('O', new LetterPattern(new boolean[][]{
            {true, true,  true,  true,  true},
            {true,  false, false, false, true},
            {true,  false, false, false, true},
            {true,  false, false, false, true},
            {true, true,  true,  true,  true}
        }));
        // P
        patterns.put('P', new LetterPattern(new boolean[][]{
            {true, true,  true,  true,  true},
            {true,  false, false, false, true},
            {true,  true, true, true, true},
            {true,  false, false, false, false},
            {true, false,  false,  false,  false}
        }));
        // Q
        patterns.put('Q', new LetterPattern(new boolean[][]{
            {true, true,  true,  true,  true},
            {true,  false, false, false, true},
            {true,  false, false, false, true},
            {true,  false, false, true, true},
            {true, true,  true,  true,  true}
        }));
        // R
        patterns.put('R', new LetterPattern(new boolean[][]{
            {true, true,  true,  true,  true},
            {true,  false, false, false, true},
            {true,  true, true, true, true},
            {true,  false, false, true, false},
            {true, false,  false,  false,  true}
        }));
        // S
        patterns.put('S', new LetterPattern(new boolean[][]{
            {true, true, true, true, true},
            {true, false, false, false, false},
            {true, true,  true,  true,  true},
            {false, false, false, false, true},
            {true, true, true, true, true}
        }));
        // T
        patterns.put('T', new LetterPattern(new boolean[][]{
            {true, true, true, true, true},
            {false, false, true, false, false},
            {false, false, true,  false,  false},
            {false, false, true, false, false},
            {false, false, true, false, false}
        }));
        // U
        patterns.put('U', new LetterPattern(new boolean[][]{
            {true, false,  false,  false,  true},
            {true, false, false, false, true},
            {true, false, false,  false,  true},
            {true, false, false, false, true},
            {true, true, true, true, true}
        }));
        // V
        patterns.put('V', new LetterPattern(new boolean[][]{
            {true, false,  false,  false,  true},
            {true, false, false, false, true},
            {false, true, false,  true,  false},
            {false, true, false, true, false},
            {false, false, true, false, false}
        }));
        // W
        patterns.put('W', new LetterPattern(new boolean[][]{
            {true, false,  false,  false,  true},
            {true, false, false, false, true},
            {true, false, false,  false,  true},
            {true, false, true, false, true},
            {true, true, false, true, true}
        }));
        // Xt
        patterns.put('X', new LetterPattern(new boolean[][]{
            {true, false,  false,  false,  true},
            {false, true, false, true, false},
            {false, false, true,  false,  false},
            {false, true, false, true, false},
            {true, false, false, false, true}
        }));
        // Y
        patterns.put('Y', new LetterPattern(new boolean[][]{
            {true, false,  false,  false,  true},
            {false, true, false, true, false},
            {false, false, true,  false,  false},
            {false, false, true, false, false},
            {false, false, true, false, false}
        }));
        // Z
        patterns.put('Z', new LetterPattern(new boolean[][]{
            {true, true,  true,  true,  true},
            {false, true, false, true, false},
            {false, false, true,  false,  false},
            {false, true, false, false, false},
            {true, false, false, false, false}
        }));
        // .
        patterns.put('.', new LetterPattern(new boolean[][]{
            {false, false,  false,  false,  false},
            {false, false, false, false, false},
            {false, false, false,  false,  false},
            {false, false, false, false, false},
            {true, false, false, false, false}
        }));
        // -
        patterns.put('-', new LetterPattern(new boolean[][]{
            {false, true,  false,  true,  true},
            {false, true, false, true, true},
            {false, false, false,  false,  true},
            {false, true, true, true, false},
            {true, false, false, false, true}
        }));
        // _
        patterns.put('_', new LetterPattern(new boolean[][]{
            {true,true,true,false,false,true,true,true},
            {false,false,true,true,true,true,false,false},
            {false,false,true,true,true,true,false,false},
            {false,true,false,true,true,false,true,false},
            {false,true,true,true,true,true,true,false},
            {false,false,false,true,true,false,false,false},
            {false,true,true,false,false,true,true,false},
            {false,false,true,false,false,true,false,false},
        }));// /
        patterns.put(':', new LetterPattern(new boolean[][]{
            {false, false,  false,  false,  false},
            {false, false, true, false, false},
            {false, false, false,  false,  false},
            {false, false, true, false, false},
            {false, false, false, false, false}
        }));
    }

    public static LetterPattern get(char c) {
        return patterns.get(Character.toUpperCase(c));
    }
}
