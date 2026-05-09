import Phaser from 'phaser';

export default class GameScene extends Phaser.Scene {
    constructor(config) {
        super({key: 'GameScene'}, config);

        this.config = config;
    }

    init() {
        this.cursors = null;
    }

    create() {
        this.createBackground();

        this.createEnemy();

        const centerX = this.cameras.main.width / 2;
        const centerY = this.cameras.main.height / 2;

        this.add.text(
            centerX,
            centerY - 200,
            'Animation by Frames',
            {
                fontSize: '40px',
                fontFamily: 'Arial',
                color: '#ffffff'
            }
        ).setOrigin(0.5);
    }

    createBackground() {
        this.add.image(
            this.config.width * 0.5,
            this.config.height * 0.5,
            'background'
        );
    }

    createEnemy() {
        this.enemy = this.add.sprite(
            this.config.width * 0.5,
            this.config.height * 0.5,
            'enemy_idle_1'
        ).setScale(2);

        this.anims.create({
            key: 'enemy_idle',
            frames: [
                {key: 'enemy_idle_1'},
                {key: 'enemy_idle_2'},
                {key: 'enemy_idle_3'},
                {key: 'enemy_idle_4'},
                {key: 'enemy_idle_5'},
                {key: 'enemy_idle_6'}
            ],
            frameRate: 4,
            repeat: -1
        })

        this.enemy.play('enemy_idle');
    }
}