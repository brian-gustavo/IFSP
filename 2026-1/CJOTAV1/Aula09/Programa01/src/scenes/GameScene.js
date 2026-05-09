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
        const width = this.sys.game.config.width;
        const height = this.sys.game.config.height;

        this.add.image(width * 0.5, height * 0.5, 'background');
        this.createEnemy(width, height);

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

    createEnemy(w, h) {
        this.enemy = this.add.sprite(
            w * 0.5,
            h * 0.5,
            'enemy_idle1'
        ).setScale(2);

        this.anims.create({
            key: 'enemy_idle',
            frames: [
                {key: 'enemy_idle1'},
                {key: 'enemy_idle2'},
                {key: 'enemy_idle3'},
                {key: 'enemy_idle4'},
                {key: 'enemy_idle5'},
                {key: 'enemy_idle6'}
            ],
            frameRate: 4,
            repeat: -1
        })

        this.enemy.play('enemy_idle');
    }
}