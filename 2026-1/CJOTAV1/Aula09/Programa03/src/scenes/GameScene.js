import Phaser from 'phaser';

export default class GameScene extends Phaser.Scene {
    constructor(config) {
        super({ key: 'GameScene' }, config);
        this.config = config;
    }

    init() {
        this.gravity = 600;
        this.distanceToAttack = 200;

        this.player = null;
        this.playerSpeed = 200;
        this.playerJumpForce = 400;

        this.enemy = null;
        this.enemySpeed = 70;
        this.enemyDirection = -1;
    }

    create() {
        this.createBackground();
        this.createGround();

        this.registerPlayerAnimations();
        this.registerEnemyAnimations();

        this.createPlayer();
        this.createEnemy();

        this.cursorKeys = this.input.keyboard.createCursorKeys();
        this.input.mouse.disableContextMenu();
    }

    update() {
        const { left, right, up, space } = this.cursorKeys;
        const isUpJustDown = Phaser.Input.Keyboard.JustDown(up);
        const isSpaceJustDown = Phaser.Input.Keyboard.JustDown(space);

        const playerOnFloor = this.player.body.onFloor();
        const currentPlayerAnim = this.player.anims.currentAnim?.key;
        const isPlayerPlaying = animKey => this.player.anims.isPlaying && currentPlayerAnim === animKey;

        if (isPlayerPlaying('player_attack')) {
            this.player.setVelocityX(0);
            return;
        }

        if (left.isDown) {
            this.player.setVelocityX(-this.playerSpeed);
            this.player.setFlipX(true);

            if (!isPlayerPlaying('player_run') && playerOnFloor) {
                this.player.play('player_run', true);
            }
        } else if (right.isDown) {
            this.player.setVelocityX(this.playerSpeed);
            this.player.setFlipX(false);

            if (!isPlayerPlaying('player_run') && playerOnFloor) {
                this.player.play('player_run', true);
            }
        } else {
            this.player.setVelocityX(0);

            if (!isPlayerPlaying('player_idle') && playerOnFloor) {
                this.player.play('player_idle', true);
            }
        }

        if (isUpJustDown && playerOnFloor) {
            this.player.setVelocityY(-this.playerJumpForce);
            this.player.play('player_jump', true);
        }

        if (isSpaceJustDown && playerOnFloor) {
            this.player.setVelocityX(0);
            this.player.play('player_attack', true);
        }

        if (!playerOnFloor && this.player.body.velocity.y > 0) {
            this.player.play('player_fall', true);
        }

        const distance = Phaser.Math.Distance.Between(
            this.player.x, this.player.y,
            this.enemy.x, this.enemy.y
        );

        if (distance < this.distanceToAttack) {
            this.enemy.setVelocityX(0);
            
            if (this.enemy.anims.currentAnim?.key !== 'enemy_attack') {
                this.enemy.play('enemy_attack', true);
            }
            
            this.enemy.setFlipX(this.player.x < this.enemy.x);
        } else {
            if (this.enemy.anims.currentAnim?.key === 'enemy_attack' && this.enemy.anims.isPlaying) {
                this.enemy.setVelocityX(0);
            } else {
                this.enemy.setVelocityX(this.enemyDirection * this.enemySpeed);
                this.enemy.play('enemy_walk', true);

                if (this.enemy.x <= 150) {
                    this.enemyDirection = 1;
                }
                else if (this.enemy.x >= this.config.width - 150) {
                    this.enemyDirection = -1;
                }

                this.enemy.setFlipX(this.enemyDirection === -1);
            }
        }
    }
    
    createBackground() {
        this.add.image(
            this.config.width * 0.5,
            this.config.height * 0.5,
            'background'
        ).setDisplaySize(this.config.width, this.config.height);
    }

    createGround() {
        this.platforms = this.physics.add.staticGroup();

        const ground = this.add.rectangle(
            this.config.width * 0.5, 
            615, 
            this.config.width, 
            30, 
            0x000000, 0
        );
        
        this.physics.add.existing(ground, true);
        this.platforms.add(ground);
    }

    createPlayer() {
        this.player = this.physics.add.sprite(this.config.width * 0.2, 500, 'player').setScale(2.5);
        this.player.body.setGravityY(this.gravity);
        this.player.setCollideWorldBounds(true);
        this.physics.add.collider(this.player, this.platforms);
        
        this.player.body.setSize(20, 28);
        this.player.body.setOffset(6, 4);
    }

    createEnemy() {
        this.enemy = this.physics.add.sprite(this.config.width * 0.7, 450, 'enemy');
        this.enemy.body.setGravityY(this.gravity);
        this.enemy.setCollideWorldBounds(true);
        this.physics.add.collider(this.enemy, this.platforms);
        
        this.enemy.body.setSize(70, 110);
        this.enemy.body.setOffset(109, 50);
    }

    registerPlayerAnimations() {
        this.anims.create({
            key: 'player_idle',
            frames: this.anims.generateFrameNumbers('player', { start: 0, end: 1 }),
            frameRate: 4,
            repeat: -1
        });

        this.anims.create({
            key: 'player_run',
            frames: this.anims.generateFrameNumbers('player', { start: 24, end: 31 }),
            frameRate: 10,
            repeat: -1
        });

        this.anims.create({
            key: 'player_jump',
            frames: this.anims.generateFrameNumbers('player', { start: 32, end: 34 }),
            frameRate: 10,
            repeat: 0
        });

        this.anims.create({
            key: 'player_fall',
            frames: this.anims.generateFrameNumbers('player', { start: 40, end: 42 }),
            frameRate: 10,
            repeat: -1
        });

        this.anims.create({
            key: 'player_attack',
            frames: this.anims.generateFrameNumbers('player', { start: 56, end: 61 }),
            frameRate: 14,
            repeat: 0
        });
    }

    registerEnemyAnimations() {
       this.anims.create({
            key: 'enemy_walk',
            frames: this.anims.generateFrameNumbers('enemy', { start: 0, end: 5 }),
            frameRate: 8,
            repeat: -1
        });

        this.anims.create({
            key: 'enemy_attack',
            frames: this.anims.generateFrameNumbers('enemy', { start: 44, end: 58 }),
            frameRate: 14,
            repeat: 0
        });
    }
}