package io.github.some_example_name.simulation;

import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.graphics.GL20;
import com.badlogic.gdx.math.Vector2;
import io.github.some_example_name.drone.Drone;
import io.github.some_example_name.render.DroneRenderer;
import io.github.some_example_name.text.WordMapper;
import io.github.some_example_name.text.WordShape;
import io.github.some_example_name.utils.Constants;

// Gestor de all
public class Simulation {
    private WordMapper wordMapper;
    private DroneManager droneManager;
    private DroneRenderer droneRenderer;
    private static final int DRONE_COUNT = 300;

    public Simulation() {
        droneManager=new DroneManager(Constants.MIN_DRONE_DISTANCE);
        droneRenderer=new DroneRenderer();
        wordMapper=new WordMapper(15f, 15f);
        createDrones(DRONE_COUNT);
    }

    // Recibe una palabra desde la UI y recalcula la forma
    public void setWord(String word) {
        if(word==null || word.isEmpty()) {
            return;
        }
        // La palabra spawnea en 0,0 para medirla
        WordShape tempShape = wordMapper.map(word, new Vector2(0, 0)); // Pasamos la palabra a geometria
        float screenWidth = Gdx.graphics.getWidth();
        float screenHeight = Gdx.graphics.getHeight();

        float originX = (screenWidth - tempShape.getWidth()) / 2f;
        float originY = (screenHeight - tempShape.getHeight()) / 2f;

        Vector2 centeredOrigin = new Vector2(originX, originY);

        WordShape centeredShape = wordMapper.map(word, centeredOrigin);
        droneManager.assignWordShape(centeredShape);
    }

    private void createDrones(int count) {
        float margin = 10f;
        float spacing = Constants.MIN_DRONE_DISTANCE-10f;
        float screenWidth = Gdx.graphics.getWidth();
        float screenHeight = Gdx.graphics.getHeight();

        int columns = (int)((screenWidth - margin * 2) / spacing);
        if(columns <= 0)
            columns = 1;
        for(int i = 0; i < count; i++) {
            int col = i % columns;
            int row = i / columns;
            float x = margin + col * spacing;
            float y = margin + row * spacing;

            // Evitar salir por arriba
            if(y > screenHeight - margin) {
                break;
            }
            Drone drone = new Drone(new Vector2(x, y),Constants.DRONE_SPEED);
            droneManager.addDrone(drone);
        }
    }

    public void resetDrones() {
        droneManager.clearDrones();
        createDrones(DRONE_COUNT);
    }

    public void update(float deltaTime) {
        droneManager.update(deltaTime);
    }

    public void render() {
        Gdx.gl.glClearColor(0, 0, 0, 1);
        Gdx.gl.glClear(GL20.GL_COLOR_BUFFER_BIT);
        droneRenderer.render(droneManager.getDrones());
    }

    public void dispose() {
        droneRenderer.dispose();
    }
}
