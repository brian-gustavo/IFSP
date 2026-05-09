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

        this.setupTouchEvents();
    }

    update(time, delta) {
        // TODO
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
            this.config.width * 0.5,
            300,
            'player'
        )

        this.player.setCollideWorldBounds(true);
    }

    setupTouchEvents() {
       this.input.on('pointerdown', (pointer) => {
            console.log("Tela tocada em X: ${pointer.x} e Y: ${pointer.y}!");

            this.player.setPosition(pointer.x, pointer.y);
       })

       this.input.on('pointerup', (pointer) => {
            console.log("Toque liberado!");
       })

       this.input.on('pointermove', (pointer) => {
            if (pointer.isDown) {
                console.log("Arrastando toque para X: ${pointer.x} e Y: ${pointer.y}!");

                this.player.setPosition(pointer.x, pointer.y);
            }
       })
    }
}