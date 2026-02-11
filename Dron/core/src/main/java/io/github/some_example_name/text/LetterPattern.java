package io.github.some_example_name.text;

import java.util.ArrayList;
import java.util.List;
import com.badlogic.gdx.math.Vector2;

// Para manejar la formacion de palabras
public class LetterPattern {
    private boolean[][] pattern;
    private int width;
    private int height;

    public LetterPattern(boolean[][] pattern) {
        this.pattern = pattern;
        this.height = pattern.length;
        this.width = pattern[0].length;
    }

    // Asignamos los destinos de los drones a las posiciones  obtenidas del wordShape
    public List<Vector2> toPoints(Vector2 origin, float spacing) {
        List<Vector2> points = new ArrayList<>(); // Lista con todas las coordenadas de los puntos de patron
        for(int y=0;y<height;y++) {
            for(int x=0;x<width;x++) {
                if(pattern[y][x]) {
                    float px=origin.x+x*spacing;
                    float py=origin.y+(height - y - 1) * spacing;
                    points.add(new Vector2(px, py));
                }
            }
        }
        return points;
    }

    public int getWidth() {
        return width;
    }
}
