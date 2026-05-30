import Phaser from 'phaser';
import Player from '../entities/Player.js';

export default class GameScene extends Phaser.Scene {
    constructor(config) {
        super({key: 'GameScene'});
        this.config = config;

        this.score = 0;
        this.scoreText = null;
    }

    init() {
        this.cursors = this.input.keyboard.createCursorKeys();

        this.score = 0;
    }

    create() {
        const { width, height } = this.sys.game.config;
        this.config = { width, height };

        this.createBackground();
        this.createPlayer();

        this.remedios = this.physics.add.group();

        this.time.addEvent({
            delay: 1500,
            callback: this.spawnRemedio,
            callbackScope: this,
            loop: true
        });

        this.physics.add.overlap(
            this.player, 
            this.remedios, 
            this.coletarRemedio, 
            null, 
            this
        );

        this.scoreText = this.add.text(20, 20, 'Pontos: 0', {
            fontSize: '32px',
            fill: '#ffffff',
            fontFamily: 'Arial, sans-serif',
            stroke: '#000000',
            strokeThickness: 4
        });
    }

    update(time, delta) {
        if (this.player && this.player.update) {
            this.player.update(this.cursors);
        }

        this.remedios.getChildren().forEach(remedio => {
            if (remedio.y > this.config.height) {
                remedio.destroy();
            }
        });
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
        const startY = this.config.height - 120;

        this.player = new Player(this, startX, startY);
    }

    spawnRemedio() {
        const xAleatorio = Phaser.Math.Between(50, this.config.width - 50);
        const tipoRemedio = Phaser.Math.RND.pick(['caixa', 'cartela']);

        const remedio = this.remedios.create(xAleatorio, 0, tipoRemedio);
        
        remedio.setScale(0.15);
        remedio.setBounce(0.2);

        const anguloAlvo = Phaser.Math.RND.pick([-360, 360]);

        this.tweens.add({
            targets: remedio,
            angle: anguloAlvo,
            duration: 3000,
            ease: 'Linear',
            repeat: -1
        });
    }

    coletarRemedio(player, remedio) {
        remedio.destroy();

        this.score += 1;

        this.scoreText.setText('Pontos: ' + this.score);
    }
}