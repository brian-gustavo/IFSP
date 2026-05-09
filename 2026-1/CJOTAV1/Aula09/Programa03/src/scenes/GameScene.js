import Phaser from 'phaser';

export default class GameScene extends Phaser.Scene {
    constructor(config) {
        super({key: 'GameScene'}, config);

        this.config = config;
    }

    init() {
        this.gravity = 500;

        this.distanceToAttack = 250;

        this.player = null;
        this.playerSpeed = 200;
        this.playerJumpForce = 520;

        this.enemy = null;
        this.enemySpeed = 80;
        this.enemyDirection = -4;
    }

    create() {
        this.createBackground();
        this.createGround();

        this.registerPlayerAnimations();
        this.registerEnemyAnimations();

        this.createPlayer();
        this.createEnemy();

        this.player.body.setGravityY(this.gravity);
        this.player.setCollideWorldBounds(true);

        this.enemy.body.setGravityY(this.gravity);
        this.enemy.setCollideWorldBounds(true);

        this.cursorKeys = this.input.keyboard.createCursorKeys();
        this.input.mouse.disableContextMenu();

        this.enemy.on('animationstart', (anim) => {
            if (anim.key === 'enemy_attack') {
                this.enemy.body.setSize(160, 100);

                const offsetX = this.enemy.body.flipX ? 85 : 40;
                this.enemy.body.setOffset(offsetX, 60);
            }
        });

        this.enemy.on('animationstart', (anim) => {
            if (anim.key === 'enemy_walk') {
                this.enemy.body.setSize(90, 100);
                this.enemy.body.setOffset(100, 60);
            }
        });
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

    update() {
        const { left, right, up, down, space } = this.cursorKeys;

        const isUpJustDown = Phaser.Input.Keyboard.JustDown(up);

        const isSpaceJustDown = Phaser.Input.Keyboard.JustDown(space);

        const playerOnFloor = this.player.body.onFloor();

        const currentPlayerAnim = this.player.anims.currentAnim?.key;

        const isPlayerPlaying = animKey => this.player.anims.isPlaying && currentPlayerAnim === animKey;

        // TODO...
    }
}