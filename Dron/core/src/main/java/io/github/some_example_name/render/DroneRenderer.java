package io.github.some_example_name.render;

import com.badlogic.gdx.graphics.glutils.ShapeRenderer;
import io.github.some_example_name.drone.Drone;
import io.github.some_example_name.drone.DroneState;
import io.github.some_example_name.utils.Constants;
import java.util.List;

// Para dibujar a los drones
public class DroneRenderer {
    private ShapeRenderer shapeRenderer;
    public DroneRenderer() {
        shapeRenderer = new ShapeRenderer();
    }

    public void render(List<Drone> drones) {
        // Vai a inicial un lote de formas del tipo filled, osea formas rellenas
        shapeRenderer.begin(ShapeRenderer.ShapeType.Filled);
        for(Drone drone : drones) {
            // Color según estado (solo visual)
            if(drone.getState() == DroneState.MOVING) {
                shapeRenderer.setColor(0,1,0,1); // verde
            } else{
                shapeRenderer.setColor(1,0,0,1); // rojo
            }

            shapeRenderer.circle(
                drone.getPosition().x,
                drone.getPosition().y,
                Constants.DRONE_RADIUS
            );
        }

        shapeRenderer.end();
    }

    // El """"destructor""""
    public void dispose() {
        shapeRenderer.dispose();
    }
}
