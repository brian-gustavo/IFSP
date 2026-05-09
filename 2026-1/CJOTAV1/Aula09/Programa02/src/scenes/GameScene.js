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
            'Animation by Spritesheet',
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
            'enemy'
        ).setScale(3);

        this.anims.create({
            key: 'cleave',
            frames: this.anims.generateFrameNumbers(
                'enemy',
                {
                    start: 44,
                    end: 58
                }
            ),
            frameRate: 16,
            repeat: -1
        });

        this.enemy.play('cleave');
    }
}