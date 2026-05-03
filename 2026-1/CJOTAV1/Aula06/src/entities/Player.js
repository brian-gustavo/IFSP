import Phaser from 'phaser';

export default class Player extends Phaser.Physics.Arcade.Sprite {
    constructor(scene, x, y) {
        super(scene, x, y, 'player');
        this.scene = scene;
        this.init();
    }

    init() {
        this.scene.add.existing(this);
        this.scene.physics.add.existing(this);

        this.body.allowGravity = true;

        this.setCollideWorldBounds(true);
        
        this.setGravityY(500);
        this.playerSpeed = 200;
        this.jumpForce = 450;
    }

    update(cursors) {
        if (cursors.left.isDown) {
            this.setVelocityX(-this.playerSpeed);
            this.setFlipX(true);
        } else if (cursors.right.isDown) {
            this.setVelocityX(this.playerSpeed);
            this.setFlipX(false);
        } else {
            this.setVelocityX(0);
        }

        if (cursors.up.isDown && (this.body.onFloor() || this.body.blocked.down)) {
            this.setVelocityY(-this.jumpForce);
        }
    }
}