import Phaser from 'phaser';

import Player from '../entities/Player.js';

export default class GameScene extends Phaser.Scene {
    constructor(config) {
        super({key: 'GameScene'});

        this.config = config;
    }

    init() {
        this.player = null;
        this.targetPosition = null;
        this.playerSpeed = 100;
        this.playerDrag = 0.95;
        this.minDistance = 10;
    }

    create() {
        this.createBackground();

        this.createPlayer();

        this.targetPosition = new Phaser.Math.Vector2(
            this.player.x,
            this.player.y
        );

        this.input.mouse.disableContextMenu();

        this.setupTouchEvents();
    }

    update(time, delta) {
        this.playerManager(time);
    }

    createBackground() {
        this.add.image(
            this.config.width * 0.5,
            this.config.height * 0.5,
            'background'
        );
    }

    createPlayer() {
        this.player = this.physics.add.sprite(this.config.width * 0.5, 300, 'player').setOrigin(0.5, 0.5);

        this.player.setDamping(true);

        this.player.setDrag(this.playerDrag);

        this.player.setCollideWorldBounds(true);
    }

    setupTouchEvents() {
       this.input.on('pointerdown', (pointer) => {
            this.targetPosition.set(pointer.x, pointer.y);

            const xMark = this.add.text(pointer.x, pointer.y, 'X', {
                font: '60px Arial',
                fill: '#ff0000'
            }).setOrigin(0.5);

            this.time.delayedCall(3000, () => xMark.destroy());
       })
    }

    playerManager(time) {
        this.player.y += Math.cos((time / 1000) * 2) + 0.5;

        const distance = Phaser.Math.Distance.Between(
            this.player.x,
            this.player.y,
            this.targetPosition.x,
            this.targetPosition.y
        );

        if (distance > this.minDistance) {
            const angle = Phaser.Math.Angle.Between(
                this.player.x,
                this.player.y,
                this.targetPosition.x,
                this.targetPosition.y
            );

            this.player.rotation = Phaser.Math.Angle.RotateTo(
                this.player.rotation,
                angle + Phaser.Math.DegToRad(-90),
                0.03
            );

            const moveAngle = this.player.rotation - Phaser.Math.DegToRad(-90);

            const velocity = this.physics.velocityFromRotation(
                moveAngle,
                this.playerSpeed,
                this.player.body.velocity
            );
        } else {
            this.player.body.setVelocity(0, 0);
        }
    }
}