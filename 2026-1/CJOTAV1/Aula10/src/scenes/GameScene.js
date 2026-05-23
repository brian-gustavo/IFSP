import Phaser from 'phaser';

export default class GameScene extends Phaser.Scene {
    constructor(config) {
        super({key: 'GameScene'}, config);

        this.config = config;
    }

    init() {
    }

    create() {
        this.createBackground();
        this.createPlayer();
        this.createCoke();

        const centerX = this.cameras.main.width / 2;
        const centerY = this.cameras.main.height / 2;

        this.add.text(
            centerX,
            50,
            'Animações Interpoladas e Fonte Bitmap',
            {
                fontSize: '40px',
                fontFamily: 'Arial',
                color: '#ffffff'
            }
        ).setShadow(2, 2, '#000000', 3, true, true)
         .setOrigin(0.5);

        this.add.bitmapText(
            centerX,
            130,
            'pokelino',
            'Pokélino: Gotta Catch All the Cokes!',
            50
        ).setOrigin(0.5);
    }

    createBackground() {
        this.add.image(
            this.config.width * 0.5,
            this.config.height * 0.5,
            'background'
        );
    }

    createPlayer() {
        this.anims.create({
            key: 'idle',
            frames: [
                { key: 'idle1' },
                { key: 'idle2' },
                { key: 'idle1' },
                { key: 'idle2' }
            ],
            frameRate: 3,
            repeat: -1,
            yoyo: true
        });

        this.player = this.add.sprite(
            220,
            this.config.height * 0.5 + 185,
            'idle1'
        );

        this.player.anims.play('idle');
    }

    createCoke() {
        this.coca = this.add.sprite(
            this.config.width * 0.5 + 250,
            this.config.height * 0.5 + 200,
            'coca'
        );

        this.tweens.add({
            targets: this.coca,
            y: this.config.height * 0.5 - 60,
            duration: 3000,
            ease: 'Sine.easeInOut',
            yoyo: true,
            repeat: -1,
        });

        this.tweens.add({
            targets: this.coca,
            x: '+=8',
            duration: 300,
            yoyo: true,
            repeat: -1,
            ease: 'Power1.easeInOut'
        });
    }
}