import Phaser from 'phaser';

import Player from '../entities/Player.js';

export default class GameScene extends Phaser.Scene {
    constructor(config) {
        super({key: 'GameScene'});

        this.config = config;
    }

    init() {
        this.player = null;
    }

    create() {
        this.createBackground();

        this.createPlayer();

        this.input.mouse.disableContextMenu();

        this.input.on('wheel', (pointer, gameObjects, deltaX, deltaY, deltaZ) => {
            if (deltaY < 0) {
                console.log("Roda do mouse rolada para cima!");
            } else if (deltaY > 0) {
                console.log("Roda do mouse rolada para baixo!");
            }
        });
    }

    update(time, delta) {
        this.checkMouseButtons();
    }

    createBackground() {
        this.add.image(
            this.config.width * 0.5,
            this.config.height * 0.5,
            'background'
        );
    }

    createPlayer() {
        this.player = this.physics.add.sprite(
            this.config.width = 0.5,
            300,
            'player'
        )

        this.player.setCollideWorldBounds(true);
    }

    checkMouseButtons() {
        const pointer = this.input.activePointer;

        if (pointer.leftButtonDown()) {
            console.log("Botão esquerdo pressionado!");

            this.player.x = pointer.x;
            this.player.y = pointer.y;
        }

        if (pointer.rightButtonDown()) {
            console.log("Botão direito pressionado!");
        }

        if (pointer.middleButtonDown()) {
            console.log("Botão do meio pressionado!");
        }

        if (pointer.isDown && pointer.getDuration() > 500) {
            console.log("Botão mantido pressionado por mais de 500ms!");
        }
    }
}