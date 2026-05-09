import Phaser from 'phaser';

import Player from '../entities/Player.js';

export default class GameScene extends Phaser.Scene {
    constructor(config) {
        super({key: 'GameScene'});

        this.config = config;
    }

    init() {
        this.cursors = this.input.keyboard.createCursorKeys();
    }

    create() {
        const { width, height } = this.sys.game.config;
    
        this.config = { width, height };

        this.createBackground();

        this.createPlayer();
    }

    update(time, delta) {
        if (this.player && this.player.update) {
            this.player.update(this.cursors);
        }
    }

    createBackground() {
        this.add.image(
            this.config.width * 0.5,
            this.config.height * 0.5,
            'cenario'
        );
    }

    createPlayer() {
        const startX = this.config.width * 0.5;
        const startY = this.config.height - 235;

        this.player = new Player(this, startX, startY);
    }
}