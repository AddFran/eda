package io.github.some_example_name.simulation;

import com.badlogic.gdx.math.Vector2;
import io.github.some_example_name.drone.Drone;
import io.github.some_example_name.drone.DroneState;
import io.github.some_example_name.text.WordShape;

import java.util.ArrayList;
import java.util.List;

// Es lo q necesita el dron para comportarse, la logica de moviminetos
public class DroneManager {
    private List<Drone> drones;
    private float minDistance;

    public DroneManager(float minDistance) {
        this.drones = new ArrayList<>();
        this.minDistance = minDistance;
    }

    // Aux
    public void addDrone(Drone drone) {
        drones.add(drone);
    }

    public List<Drone> getDrones() {
        return drones;
    }

    // Update main
    public void update(float deltaTime) {
        // Primero, decidir quien se mueve y quien se detiene
        handleDroneInteractions(); // Recor, tenemos nuestra lista de drones con los puntos donde ir ya asignados
        // Segundo, actualizar movimiento
        for(Drone drone : drones) {
            drone.update(deltaTime);
        }
    }

    // ""Logica"" de los drones, agarra un dron y luego verifica si hay otro dron enfernte
    private void handleDroneInteractions() {
        for(Drone current : drones) {
            boolean blocked = false;
            if(current.getState() == DroneState.MOVING) {
                for(Drone other : drones) {
                    if(current == other)
                        continue;
                    if(isDroneInFront(current, other)) {
                        blocked = true;
                        break;
                    }
                }
            }
            if(blocked) {
                current.stop();
            }else {
                current.resume();
            }
        }
    }

    // Determina si 'other' está enfrente de 'current'
    private boolean isDroneInFront(Drone current, Drone other) {
        Vector2 toOther = new Vector2(other.getPosition()).sub(current.getPosition()); // Vector entre ambos puntos
        float distance = toOther.len(); // Distancia entre ambos

        // Si la distancia es mayor a la minima distancia
        if(distance > minDistance) {
            return false; // No esta al frente
        }

        // En cambio...
        // Obtiene el vector direccion enter su destino y su posicion actual
        Vector2 direction = new Vector2(current.getTarget()).sub(current.getPosition())
            .nor();

        // Producto punto para saber si está enfrente
        float dot = direction.dot(toOther.nor()); // Si "toOther.nor()" esta al frente
        return dot > 0.6f; // Segun el resukltado de dot es cuanto esta alineado
    }

    public void assignWordShape(WordShape shape) {
        List<Vector2> points = shape.getPoints(); // Shape almacena todos los puntos/coordenadas de los drones
        int count = Math.min(drones.size(),points.size()); // Menor entre ambas listas, de drones y de puntos
        for(int i = 0; i < count; i++) {
            drones.get(i).moveTo(points.get(i)); // Asignamos los puntos a los drones
            // Los drones ya tienen la orden de mmoverse a su sitio
        }
        // Drones NO usados regresan a tierra
        for(int i = count; i < drones.size(); i++) {
            drones.get(i).returnHome();
        }
    }

    public void clearDrones() {
        drones.clear();
    }
}
