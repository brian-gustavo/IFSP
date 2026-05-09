import Phaser from 'phaser';

export default class GameScene extends Phaser.Scene {
    constructor(config) {
        super({key: 'GameScene'}, config);

        this.config = config;
    }

    init() {
        this.cursors = null;

        this.player = null;
        this.playerSpeed = 200;

        this.cheese = null;
        this.cheesesCollected = 0;
        this.TOTAL_CHEESES = 5;

        this.score = 0;
        this.scoreText = null;
    }

    create() {
        this.createBackground();

        this.createPlayer();

        this.createCheese();

        this.add.image(
            0,
            this.config.height - 241,
            'fence'
        ).setOrigin(0)
         .setDepth(10);

        this.scoreText = this.add.text(
            10,
            10,
            'QUEIJOS: 0',
            {
                fontSize: '32px',
                fill: '#ffffff'
            }
        ).setShadow(1, 1, '#000000', 3);

        this.cursors = this.input.keyboard.createCursorKeys();
    }

    update() {
        this.movePlayerManager();
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
        );

        this.player.setCollideWorldBounds(true);

        const newWidth = this.player.width * 0.85;
        const newHeight = this.player.height * 0.5;

        this.player.body.setSize(newWidth, newHeight);

        const offsetX = (this.player.width - newWidth) / 2;
        const offsetY = (this.player.height - newHeight) / 2;

        this.player.body.setOffset(offsetX, offsetY + 30);
    }

    movePlayerManager() {
        this.player.setVelocity(0);

        if (this.cursors.left.isDown) {
            this.player.setVelocityX(-this.playerSpeed);
            this.player.flipX = true;
        } else if (this.cursors.right.isDown) {
            this.player.setVelocityX(this.playerSpeed);
            this.player.flipX = false;
        }

        if (this.cursors.up.isDown) {
            this.player.setVelocityY(-this.playerSpeed);
        } else if (this.cursors.down.isDown) {
            this.player.setVelocityY(this.playerSpeed);
        }
    }

    createCheese() {
        if (this.cheese) {
            this.cheese.destroy();
        }

        const randomCheeseType = Phaser.Math.Between(1, this.TOTAL_CHEESES);
        const cheeseKey = 'cheese' + randomCheeseType;

        const x = Phaser.Math.Between(
            60,
            this.config.width - 60
        );

        const y = Phaser.Math.Between(
            150,
            this.config.height - 40
        );

        this.cheese = this.physics.add.image(
            x,
            y,
            cheeseKey
        ).setOrigin(0.5);

        const newWidth = this.cheese.width * 0.6;
        const newHeight = this.cheese.height * 0.6;

        this.cheese.body.setSize(newWidth, newHeight);

        const offsetX = (this.cheese.width - newWidth) / 2;
        const offsetY = (this.cheese.height - newHeight) / 2;

        this.physics.add.overlap(
            this.player,
            this.cheese,
            this.collectCheese,
            null,
            this
        );

        this.time.delayedCall(
            3000,
            this.createCheese,
            [],
            this
        );
    }

    collectCheese(player, cheeseToCollect) {
        this.cheesesCollected++;

        this.scoreText.setText('QUEIJOS: ' + this.cheesesCollected);

        cheeseToCollect.disableBody(true, true);
    }
}