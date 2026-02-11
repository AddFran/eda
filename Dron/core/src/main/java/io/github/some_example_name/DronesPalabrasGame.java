package io.github.some_example_name;

import com.badlogic.gdx.ApplicationAdapter;
import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.scenes.scene2d.InputEvent;
import com.badlogic.gdx.scenes.scene2d.Stage;
import com.badlogic.gdx.scenes.scene2d.ui.Skin;
import com.badlogic.gdx.scenes.scene2d.ui.TextButton;
import com.badlogic.gdx.scenes.scene2d.ui.TextField;
import com.badlogic.gdx.scenes.scene2d.utils.ClickListener;
import com.badlogic.gdx.utils.viewport.ScreenViewport;
import io.github.some_example_name.simulation.Simulation;

public class DronesPalabrasGame extends ApplicationAdapter {

    private Simulation simulation;

    // UI
    private Stage stage;
    private Skin skin;
    private TextField textField;
    private TextButton confirmButton;
    private TextButton resetButton;

    @Override
    public void create() {
        simulation = new Simulation();

        // UI config
        stage = new Stage(new ScreenViewport());
        Gdx.input.setInputProcessor(stage);

        skin = new Skin(Gdx.files.internal("uiskin.json"));

        textField = new TextField("", skin);
        textField.setMessageText("Escribe una palabra");

        confirmButton = new TextButton("Confirmar", skin);
        resetButton = new TextButton("Reiniciar", skin);

        // Posicionamiento simple
        float y = Gdx.graphics.getHeight() - 40;
        textField.setSize(200, 30);
        textField.setPosition(10, y);

        confirmButton.setSize(120, 30);
        confirmButton.setPosition(220, y);

        resetButton.setSize(120, 30);
        resetButton.setPosition(350, y);

        // Evento del botón
        confirmButton.addListener(new ClickListener() {
            @Override
            public void clicked(InputEvent event, float x, float y) {
                String word = textField.getText().trim();
                simulation.setWord(word);
            }
        });

        resetButton.addListener(new ClickListener() {
            @Override
            public void clicked(InputEvent event, float x, float y) {
                simulation.resetDrones();
            }
        });

        stage.addActor(textField);
        stage.addActor(confirmButton);
        stage.addActor(resetButton);
    }

    @Override
    public void render() {
        simulation.update(Gdx.graphics.getDeltaTime());
        simulation.render();

        stage.act(Gdx.graphics.getDeltaTime());
        stage.draw();
    }

    @Override
    public void dispose() {
        simulation.dispose();
        stage.dispose();
        skin.dispose();
    }
}
