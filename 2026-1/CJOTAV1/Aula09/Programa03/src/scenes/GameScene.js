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

    update() {
        const { left, right, up, down, space } = this.cursorKeys;
        const isUpJustDown = Phaser.Input.Keyboard.JustDown(up);
        const isSpaceJustDown = Phaser.Input.Keyboard.JustDown(space);

        const playerOnFloor = this.player.body.onFloor();

        const currentPlayerAnim = this.player.anims.currentAnim?.key;

        const isPlayerPlaying = animKey => this.player.anims.isPlaying && currentPlayerAnim === animKey;

        if (left.isDown) {
            this.player.setVelocityX(-this.playerSpeed);
            this.player.setFlipX(true);

            if (!isPlayerPlaying('player_run') && playerOnFloor) {
                this.player.play('player_run', true);
            }
        }
        else if (right.isDown) {
            this.player.setVelocityX(this.playerSpeed);
            this.player.setFlipX(false);

            if (!isPlayerPlaying('player_run') && playerOnFloor) {
                this.player.play('player_run', true);
            }
        }
        else {
            this.player.setVelocityX(0);

            if (!isPlayerPlaying('player_idle') && playerOnFloor) {
                this.player.play('player_idle', true);
            }
        }

        if (isUpJustDown && playerOnFloor) {
            this.player.setVelocityY(-this.playerJumpForce);
            this.player.play('player_jump', true);
        }

        if (isSpaceJustDown) {
            this.player.setVelocityX(0);
            this.player.play('player_attack', true);
        }

        if (!playerOnFloor && this.player.body.velocity.y > 0) {
            this.player.play('player_fall', true);
        }

        this.enemy.setVelocityX(this.enemyDirection * this.enemySpeed);

        if (this.enemy.body.blocked.left) {
            this.enemyDirection = 1;
            this.enemy.setFlipX(false);
        }

        if (this.enemy.body.blocked.right) {
            this.enemyDirection = -1;
            this.enemy.setFlipX(true);
        }

        const distance = Phaser.Math.Distance.Between(
            this.player.x,
            this.player.y,
            this.enemy.x,
            this.enemy.y
        );

        if (distance < this.distanceToAttack) {
            this.enemy.setVelocityX(0);

            if (this.enemy.anims.currentAnim?.key !== 'enemy_attack') {
                this.enemy.play('enemy_attack', true);
            }
        }
        else {
            if (this.enemy.anims.currentAnim?.key !== 'enemy_walk') {
                this.enemy.play('enemy_walk', true);
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

    createEnemy() {
        this.enemy = this.physics.add.sprite(
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

    createGround() {

    }

    createEnemy() {
        
    }
}