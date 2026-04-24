WINDOW_WIDTH = 800
WINDOW_HEIGHT = 600

PADDLE_SPEED = 400

BOERDER_TOP = 0
BOERDER_BOTTOM = WINDOW_HEIGHT
BORDER_LEFT = 0
BOERDER_RIGHT = WINDOW_WIDTH

OFF_SET_X= 10

local push = require "src.push"

require "src.Ball"
require "src.Player"

function love.load()
  math.randomseed(os.time())
  largeFont = love.graphics.newFont("assets/Font/alk-life-webfont.ttf", 32)
  smallFont = love.graphics.newFont("assets/Font/alk-life-webfont.ttf", 14)
--  local sound = love.audio.newSource("assets/gamePlayMusic.mp3", "stream")
--  love.audio.play(sound)

  player1 = Player:init(10, 0, 5, 40)
  player2 = Player:init(WINDOW_WIDTH - 15, WINDOW_HEIGHT - 50, 5, 40)

  -- Ball initialize
  ball = Ball:init(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, 10, 10)
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
      ball.dx = -ball.dx * 1.03
      ball.x = player1.x + OFF_SET_X

      if ball.dy < 0 then 
        ball.dy = -math.random(10, 150)
      else
        ball.dy = math.random(10, 150)
      end
    end

    if ball:collision(player2) then
      ball.dx = -ball.dx * 1.03
      ball.x = player2.x - OFF_SET_X

      if ball.dy < 0 then 
        ball.dy = -math.random(10, 150)
      else
        ball.dy = math.random(10, 150)
      end
    end

    if ball.y <= 0 then 
      ball.y = 0
      ball.dy = -ball.dy
    end

    if ball.y >= WINDOW_HEIGHT - 10 then
      ball.y = WINDOW_HEIGHT - 10
      ball.dy = -ball.dy
    end



    ball:update(dt)
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

  love.graphics.printf(tostring(player1.score), 0, WINDOW_HEIGHT / 2 - 100, WINDOW_WIDTH / 2 + 200, "center")
  love.graphics.printf(tostring(player2.score), 0, WINDOW_HEIGHT / 2 - 100, WINDOW_WIDTH / 2 + 600, "center")
end

function love.keypressed(key)
  if key == 'escape' then
    love.event.quit()
  end

  if key == 'space' then
    if gameState == "start" then
      gameState = "play"
    elseif gameState == "play" then
      gameState = "start"
    end
  end
end

function displayFPS()
--  love.graphics.setFont(smallFont)
  love.graphics.setColor(0, 1, 0, 1)
  love.graphics.print("FPS: " .. tostring(love.timer.getFPS()), 10, 10)
  love.graphics.setColor(1, 1, 1, 1)
end

