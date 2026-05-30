import Phaser from 'phaser';

export default class GameScene extends Phaser.Scene {
    constructor(config) {
        super({key: 'GameScene'}, config);

        this.config = config;
    }

    init() {
        this.player = null;
        this.playerSpeed = 120;
        this.distanceOffset = 10;
        this.targetPosition = null;

        this.coke = null;
        this.cokeOffset = 70;
        this.cokeAmplitude = 260;

        this.centerX = this.cameras.main.width / 2;

        this.input.mouse.disableContextMenu();

        this.setupTouchEvents();
    }

    create() {
        this.createBackground();
        this.createCoke();

        this.registerPlayerAnimations();
        this.createPlayer();
        this.player.setCollideWorldBounds(true);

        this.createText();

        this.player.on('animationstart', (anim) => {
            if (anim.key === 'player_run') {
                this.player.body.setSize(220, 310);
            }
        });

        this.player.on('animationstart', (anim) => {
            if (anim.key === 'player_idle') {
                this.player.body.setSize(424, 317);
            }
        });

        this.cursorKeys = this.input.keyboard.createCursorKeys();

        this.gameMusic = this.sound.add('gameMusic');
        this.gameMusic.setVolume(0.25);
        this.gameMusic.play({loop: true});
    }

    update() {
        const { left, right } = this.cursorKeys;

        const currentPlayerAnim = this.player.anims.currentAnim?.key;
        const isPlayerPlaying = animKey => this.player.anims.isPlaying && currentPlayerAnim === animKey;

        if (left.isDown) {
            this.player.setVelocityX(-this.playerSpeed);
            this.player.setFlipX(true);
            this.targetPosition = null;
        } else if (right.isDown) {
            this.player.setVelocityX(this.playerSpeed);
            this.player.setFlipX(false);
            this.targetPosition = null;
        } else if (this.targetPosition !== null) {
            const distance = this.targetPosition - this.player.x;

            if (Math.abs(distance) < this.distanceOffset) {
                this.player.setVelocityX(0);
                this.targetPosition = null;
            } else {
                const direction = Math.sign(distance);

                this.player.setVelocityX(this.playerSpeed * direction);
                this.player.flipX = direction < 0;
            }
        } else {
            this.player.setVelocityX(0);
        }

        if (this.player.body.velocity.x !== 0) {
            if (!isPlayerPlaying('player_run')) {
                this.player.play('player_run', true);
            }

            if (!this.playerSound.isPlaying) {
                this.playerSound.play();
            }
        } else {
            if (!isPlayerPlaying('player_idle')) {
                this.player.play('player_true', true);
            }

             if (this.playerSound.isPlaying) {
                this.playerSound.stop();
            }
        }
    }

    createBackground() {
        this.add.image(
            this.config.width * 0.5,
            this.config.height * 0.5,
            'background'
        );
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

    createPlayer() {
        // TODO...
    }

    registerPlayerAnimations() {
        // TODO...
    }

    createText() {
        this.add.text(
            centerX,
            50,
            'Trilha Musical e Efeitos Sonoros',
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
}