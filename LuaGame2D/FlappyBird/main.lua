require "src.Bird"
require "src.Pipe"

local push = require "src.push"

local pipes = {}
local spawnTimer = 0

function love.load()
  love.graphics.setDefaultFilter("nearest", "nearest")

  background = love.graphics.newImage("assets/Image/hill.png")
  bgWidth = background:getWidth()
  bgHeight = background:getHeight()

  ground = love.graphics.newImage("assets/Image/ground_with_bone.jpg")
  groundWidth = ground:getWidth()

  bird = Bird:init()

  love.window.setTitle("Flappy Bird")

  love.window.setMode(WINDOW_WIDTH, WINDOW_HEIGHT,{
  vsync = true,
  fullscreen = false,
  resizable = true

})
  push:setupScreen(VIRTUAl_WIDTH, VIRTUAl_HEIGHT, WINDOW_WIDTH, WINDOW_HEIGHT,
  {
    fullscreen = false,
    resizable = true
  })
  love.keyboard.keysPressed = {}
end

function love.draw()
  push:apply("start")

  love.graphics.draw(background, -backgroundScroll, 0)
  love.graphics.draw(background, -backgroundScroll + bgWidth, 0)

  love.graphics.draw(ground, -groundScroll, bgHeight)
  love.graphics.draw(ground, -groundScroll + groundWidth, bgHeight)

  bird:render()
  for _,pipe in pairs(pipes) do
    pipe:render()
  end

  push:apply("end")
end

function love.update(dt)
  backgroundScroll = (backgroundScroll + BACKGROUND_SCROLL_SPEED * dt) % bgWidth
  groundScroll = (groundScroll + GROUND_SCROLL_SPEED * dt) % groundWidth

  spawnTimer = spawnTimer + dt
  if spawnTimer > 2 then 
    table.insert(pipes, Pipe:init())
    spawnTimer = 0
  end

  bird:update(dt)

  for k, pipe in pairs(pipes) do
    pipe:update(dt)
    
    if pipe.x < -pipe.width then
      table.remove(pipes, k)
    end
  end

  love.keyboard.keysPressed = {}
end

function love.keypressed(key)
  love.keyboard.keysPressed[key] = true

  if key == 'escape' then
    love.event.quit()
  end

  if key == "space" then
    bird.action = "jump"
  end
end

function love.keyboard.wasPressed(key)
  if love.keyboard.keysPressed[key] then
    return true
  else
    return false
  end
end

function love.resize(w, h)
  push.resize(w, h)
end
