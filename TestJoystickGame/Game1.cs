using System;
using System.Collections.Generic;
using System.Linq;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Audio;
using Microsoft.Xna.Framework.Content;
using Microsoft.Xna.Framework.GamerServices;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework.Input;
using Microsoft.Xna.Framework.Media;
using Microsoft.Xna.Framework.Net;
using Microsoft.Xna.Framework.Storage;

namespace TestJoystickGame
{
    /// <summary>
    /// This is the main type for your game
    /// </summary>
    public class Game1 : Microsoft.Xna.Framework.Game
    {
        GraphicsDeviceManager graphics;
        SpriteBatch spriteBatch;
        private SpriteFont Font1;
        private Vector2 mFontPos;
        private int mX, mY;
        private int mEjeX;

        public Game1()
        {
            graphics = new GraphicsDeviceManager(this);
            Content.RootDirectory = "Content";
            mX = mY = 2;
            mEjeX = 0;
            XnaJoystick.Joystick.SetExclusive(this);
        }

        /// <summary>
        /// Allows the game to perform any initialization it needs to before starting to run.
        /// This is where it can query for any required services and load any non-graphic
        /// related content.  Calling base.Initialize will enumerate through any components
        /// and initialize them as well.
        /// </summary>
        protected override void Initialize()
        {
            // TODO: Add your initialization logic here

            base.Initialize();
        }

        /// <summary>
        /// LoadContent will be called once per game and is the place to load
        /// all of your content.
        /// </summary>
        protected override void LoadContent()
        {
            // Create a new SpriteBatch, which can be used to draw textures.
            spriteBatch = new SpriteBatch(GraphicsDevice);

            // TODO: use this.Content to load your game content here

            // Create a new SpriteBatch, which can be used to draw textures.
            spriteBatch = new SpriteBatch(GraphicsDevice);
            Font1 = Content.Load<SpriteFont>("SpriteFontPrueba");

            // TODO: Load your game content here            
            mFontPos = new Vector2(graphics.GraphicsDevice.Viewport.Width / 2,
                graphics.GraphicsDevice.Viewport.Height / 2);
            base.LoadContent();
        }

        /// <summary>
        /// UnloadContent will be called once per game and is the place to unload
        /// all content.
        /// </summary>
        protected override void UnloadContent()
        {
            // TODO: Unload any non ContentManager content here
        }

        /// <summary>
        /// Allows the game to run logic such as updating the world,
        /// checking for collisions, gathering input, and playing audio.
        /// </summary>
        /// <param name="gameTime">Provides a snapshot of timing values.</param>
        protected override void Update(GameTime gameTime)
        {
            //GamePadState pCurrentState = GamePad.GetState(PlayerIndex.One);
            XnaJoystick.JoystickState pJoystickState = XnaJoystick.Joystick.GetState();
            //List<DirectInputGamepad> Gamepads = DirectInputGamepad.Gamepads;

            // Allows the game to exit
            if (pJoystickState.Buttons[0] == ButtonState.Pressed || Keyboard.GetState().IsKeyDown(Keys.Escape))
                this.Exit();
            if (pJoystickState.Buttons[1] == ButtonState.Pressed)
            {
                XnaJoystick.JoystickInitEffectConstantForce pInitEffect = new XnaJoystick.JoystickInitEffectConstantForce();
                pInitEffect.Magnitude = 9700;
                pInitEffect.Type = XnaJoystick.JoystickInitEffectType.Cartesian;
                pInitEffect.Duration = XnaJoystick.JoystickInitEffect.Infinite;
                pInitEffect.SamplePeriod = 0;
                pInitEffect.Gain = XnaJoystick.JoystickEffect.NominalMax;
                pInitEffect.Axes = new XnaJoystick.JoystickInitEffectAxis[]
                {
                    new XnaJoystick.JoystickInitEffectAxis(XnaJoystick.JoystickInitEffectAxis.X,9700)
                };
                XnaJoystick.JoystickEffect pEffect = XnaJoystick.Joystick.CreateEffect(pInitEffect);
                pEffect.Start();
            }
            if (pJoystickState.DPad.Up == ButtonState.Pressed)
                mFontPos.Y--;
            if (pJoystickState.DPad.Down == ButtonState.Pressed)
                mFontPos.Y++;
            if (pJoystickState.DPad.Left == ButtonState.Pressed)
                mFontPos.X--;
            if (pJoystickState.DPad.Right == ButtonState.Pressed)
                mFontPos.X++;
            mEjeX = pJoystickState.Axis.X;

            // TODO: Add your update logic here

            base.Update(gameTime);
        }

        /// <summary>
        /// This is called when the game should draw itself.
        /// </summary>
        /// <param name="gameTime">Provides a snapshot of timing values.</param>
        protected override void Draw(GameTime gameTime)
        {
            GraphicsDevice.Clear(Color.CornflowerBlue);

            // TODO: Add your drawing code here

            spriteBatch.Begin();

            // Draw Hello World
            string output;

            output = string.Format("Test Joystick Type: {0} SubTipo: {1} Eje X: {2}", XnaJoystick.Joystick.GetCapabilities().Type, (int)XnaJoystick.Joystick.GetCapabilities().SubType, mEjeX);

            // Find the center of the string
            Vector2 FontOrigin = Font1.MeasureString(output) / 2;
            // Draw the string
            spriteBatch.DrawString(Font1, output, mFontPos, Color.LightGreen,
                0, FontOrigin, 1.0f, SpriteEffects.None, 0.5f);

            spriteBatch.End();

            base.Draw(gameTime);
        }
    }
}
