package io.github.some_example_name.drone;

import com.badlogic.gdx.math.Vector2;

// Base de los drones
public class Drone {
    private Vector2 position;
    private Vector2 target;
    private float speed;
    private DroneState state;
    private Vector2 homePosition;

    public Drone(Vector2 startPosition, float speed) {
        this.position=new Vector2(startPosition);
        this.target=new Vector2(startPosition);
        this.speed=speed;
        this.state=DroneState.STOPPED;
        this.homePosition = new Vector2(startPosition);
    }

    // Se llama en cada frame
    public void update(float deltaTime) {
        if(state==DroneState.STOPPED) {
            return;
        }
        // Vector creado a entre dos puntos (target y position) a traves de una resta
        Vector2 direction=new Vector2(target).sub(position);
        // Si ya llego al destino
        if (direction.len()<1f) {
            position.set(target);
            state=DroneState.STOPPED;
            return;
        }

        direction.nor(); // normaliza (dirección pura), osea, lo vuelve 1, vector unitario
        /*
        * direction que es un vector unitario (solo direccion) lo multiplica por speed*deltaTime para
        * que escale, luego lo suma a position para que cambie la direccion a la que se estaba
        * dirigiendo
        * */
        position.mulAdd(direction, speed * deltaTime);
    }

    // Control del dron
    public void moveTo(Vector2 newTarget) {
        this.target.set(newTarget);
        this.state=DroneState.MOVING;
    }

    public void stop() {
        this.state=DroneState.STOPPED;
    }

    public void resume() {
        // compara dos vectores, position y target, retorna que son iguales si la diferencia es menor a 1f
        if(!position.epsilonEquals(target, 1f)) {
            this.state=DroneState.MOVING;
        }
    }

    public void returnHome() {
        moveTo(homePosition);
    }

    // Getters
    public Vector2 getPosition() {
        return position;
    }
    public Vector2 getTarget() {
        return target;
    }
    public DroneState getState() {
        return state;
    }
}
