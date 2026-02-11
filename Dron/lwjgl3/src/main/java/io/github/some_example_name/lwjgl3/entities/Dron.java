package io.github.some_example_name.lwjgl3.entities;

import com.badlogic.gdx.math.Vector2;

public class Dron {
    // Posición actual
    private Vector2 position;

    // Dirección normalizada (hacia dónde mira)
    private Vector2 direction;

    // Objetivo actual
    private Vector2 target;

    // Velocidad: 0 = detenido, 1 = avanzando
    private float speed;

    // Parámetros
    private float moveSpeed; // distancia por segundo
    private float radius;    // para colisiones
}
