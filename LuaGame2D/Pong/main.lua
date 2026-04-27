--WINDOW_WIDTH = 800
--WINDOW_HEIGHT = 600


local push = require "src.push"

require "src.conf"
require "src.Ball"
require "src.Player"
require "src.utility"

function love.load()
  math.randomseed(os.time())
  largeFont = love.graphics.newFont("assets/Font/alk-life-webfont.ttf", 32)
  smallFont = love.graphics.newFont("assets/Font/alk-life-webfont.ttf", 14)
  bounceToPlayerSound = love.audio.newSource("assets/Sound/bounceToPlayer.mp3", "stream")
  bounceToTopBottomBorderSound = love.audio.newSource("assets/Sound/bounceToTopBottomBorder.mp3", "stream")
  gamePlayMusic = love.audio.newSource("assets/Sound/gamePlayMusic.mp3", "stream")
  --love.audio.play(gamePlayMusic)

  player1 = Player:init(10, 0, 
                        PLAYER_WIDTH, PLAYER_HEIGHT)
  player2 = Player:init(WINDOW_WIDTH - 15, WINDOW_HEIGHT - 50, 
                        PLAYER_WIDTH, PLAYER_HEIGHT)

  player1.name = "Player 1"
  player2.name = "Player 2"

  -- Ball initialize
  ball = Ball:init(WINDOW_WIDTH / 2 - 45, WINDOW_HEIGHT / 2, 100, 100)
  -- Ball movement
  -- Game state
  gameState = "start"

  love.window.setMode(WINDOW_WIDTH, WINDOW_HEIGHT, {
    resizable = false,
    vsync = true,
    fullscreen = false,
    fullscreentype = "desktop",
  })

  love.window.setTitle("Welcome to Pong game XD")

end

function love.update(dt)
  if love.keyboard.isDown('w') then
    player1.dy = -PADDLE_SPEED
  elseif love.keyboard.isDown('s') then
    player1.dy = PADDLE_SPEED
  else
    player1.dy = 0
  end

  if love.keyboard.isDown('up') then
    player2.dy = -PADDLE_SPEED
  elseif love.keyboard.isDown('down') then
    player2.dy= PADDLE_SPEED
  else
    player2.dy = 0
  end

  if gameState == "play" then
    if ball:collision(player1) then
      ball.dx = -ball.dx * 1.1

      if ball.dy < 0 then 
        ball.dy = -math.random(100, 200)
      else
        ball.dy = math.random(100, 200)
      end
      bounceToPlayerSound:play()
    end

    if ball:collision(player2) then
      ball.dx = -ball.dx * 1.1

      if ball.dy < 0 then 
        ball.dy = -math.random(100, 200)
      else
        ball.dy = math.random(100, 200)
      end
      bounceToPlayerSound:play()
    end

    -- Collide with top border
    if ball.y <= BOERDER_TOP then 
      ball.y = 0
      ball.dy = -ball.dy
      love.audio.play(bounceToTopBottomBorderSound)
    end

    -- Collide with bottom border
    if ball.y + ball.height >= BOERDER_BOTTOM then
      ball.y = BOERDER_BOTTOM - ball.height
      ball.dy = -ball.dy
      love.audio.play(bounceToTopBottomBorderSound)
    end

    -- Collide with left border
    if ball.x <= BORDER_LEFT then
      player2.score = player2.score + 1
      gameState = "start"
      ball:reset()
    end

    -- Collide with right border
    if ball.x + ball.width >= BOERDER_RIGHT + 10 then
      player1.score = player1.score + 1
      gameState = "start"
      ball:reset()
    end

    ball:update(dt)
  end

  if player1.score == THRESHOLD or player2.score == THRESHOLD then
    gameState = "end"
  end


  player1:update(dt)
  player2:update(dt)

end

function love.draw()
  love.graphics.clear(10/255, 90/255, 150/255, 1)
  love.graphics.setFont(largeFont)

  -- Draw 2 players
  player1:render()
  player2:render()
  -- Draw ballll
  ball:render()

  displayFPS()

  -- Draw score at (x;y)
  drawPlayerScore(player1.score, WINDOW_HEIGHT / 2 - 100, WINDOW_WIDTH / 2 + 200)
  drawPlayerScore(player2.score, WINDOW_HEIGHT / 2 - 100, WINDOW_WIDTH / 2 + 600)

  if gameState == "start" then
    love.graphics.setColor(0, 1, 0, 1)
    love.graphics.printf("Press Enter to play", 0, WINDOW_HEIGHT / 2 - 200, WINDOW_WIDTH, "center")
    love.graphics.setColor(1, 1, 1, 1)
  end

  if gameState == "end" then
    love.graphics.setColor(0, 1, 0, 1)
    drawWinner(player1, player2)
    love.graphics.setColor(1, 1, 1, 1)
  elseif gameState == "play" then
  end
end

function love.keypressed(key)
  if key == 'escape' then
    love.event.quit()
  end

  if key == 'space' then
    if gameState == "start" then
      gameState = "play"
      --gamePlayMusic:play()
    elseif gameState == "play" then
      gameState = "start"
      --gamePlayMusic:pause()
    elseif gameState == "end" then
      player1:reset()
      player2:reset()
      ball:reset()
      gameState = "start"
    end
  end

end


