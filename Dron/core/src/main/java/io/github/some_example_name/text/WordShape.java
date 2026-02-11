package io.github.some_example_name.text;

import com.badlogic.gdx.math.Vector2;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

// Basicamente es una lista de vectores para representar puntos
public class WordShape {
    private final List<Vector2> points;

    public WordShape() {
        this.points = new ArrayList<>();
    }

    public WordShape(List<Vector2> points) {
        this.points = new ArrayList<>(points);
    }

    public void addPoint(Vector2 point) {
        points.add(point);
    }

    public void addPoints(List<Vector2> newPoints) {
        points.addAll(newPoints);
    }


    // Devuelve una vista de solo lectura
    public List<Vector2> getPoints() {
        return Collections.unmodifiableList(points);
    }

    public int size() {
        return points.size();
    }

    public boolean isEmpty() {
        return points.isEmpty();
    }

    // Para trabajar el centrado de palabras
    public float getMinX() {
        float min = Float.MAX_VALUE;
        for(Vector2 p : points) {
            min = Math.min(min, p.x);
        }
        return min;
    }
    public float getMaxX() {
        float max = Float.MIN_VALUE;
        for(Vector2 p : points) {
            max = Math.max(max, p.x);
        }
        return max;
    }
    public float getMinY() {
        float min = Float.MAX_VALUE;
        for(Vector2 p : points) {
            min = Math.min(min, p.y);
        }
        return min;
    }
    public float getMaxY() {
        float max = Float.MIN_VALUE;
        for(Vector2 p : points) {
            max = Math.max(max, p.y);
        }
        return max;
    }
    public float getWidth() {
        if(points.isEmpty())
            return 0;
        return getMaxX() - getMinX();
    }
    public float getHeight() {
        if(points.isEmpty())
            return 0;
        return getMaxY() - getMinY();
    }
}
