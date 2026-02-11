package io.github.some_example_name.text;

import com.badlogic.gdx.math.Vector2;
import java.util.List;

// "Mapear" las palabras
public class WordMapper {
    private float pointSpacing; // Disstancia entre puntos
    private float letterSpacing; // Distancia entre letras

    public WordMapper(float pointSpacing, float letterSpacing) {
        this.pointSpacing = pointSpacing;
        this.letterSpacing = letterSpacing;
    }

    // Convertir palabra en una lista de vectores
    public WordShape map(String word, Vector2 origin) {
        WordShape wordShape = new WordShape();
        float offsetX = 0f; // Aux para indicar o salta pixeles

        for (char c : word.toCharArray()) {
            // matriz vacia | matriz con el patron de c
            LetterPattern pattern = LetterPatterns.get(c);

            // Si la letra no existe, saltamos espacio
            if(pattern == null) {
                offsetX += letterSpacing;
                continue;
            }

            // Indicamos de donde parte cada letra
            Vector2 letterOrigin = new Vector2(
                origin.x + offsetX,
                origin.y
            );

            // Convertimos el patron obtenido en puntos
            List<Vector2> letterPoints = pattern.toPoints(letterOrigin, pointSpacing);
            // Añadimos los puntos
            wordShape.addPoints(letterPoints);

            // Avanzamos en X según el ancho de la letra
            offsetX += pattern.getWidth() * pointSpacing + letterSpacing;
        }

        return wordShape;
    }
}
