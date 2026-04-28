

function love.load()
  love.graphics.setDefaultFilter("nearest", "nearest")

  background = love.graphics.newImage("assets/Image/hill.png")
  bgWidth = background:getWidth()
  bgHeight = background:getHeight()
  ground = love.graphics.newImage("assets/Image/ground_with_bone.jpg")
  groundWidth = ground:getWidth()

  love.window.setTitle("Flappy Bird")

  love.window.setMode(WINDOW_WIDTH, WINDOW_HEIGHT,{
  vsync = true,
  fullscreen = false,
  resizable = true
})
end

function love.draw()
  love.graphics.draw(background, -backgroundScroll, 0)
  love.graphics.draw(background, -backgroundScroll + bgWidth, 0)

  love.graphics.draw(ground, -groundScroll, bgHeight)
  love.graphics.draw(ground, -groundScroll + groundWidth, bgHeight)
end

function love.update(dt)
  backgroundScroll = (backgroundScroll + BACKGROUND_SCROLL_SPEDD * dt) % bgWidth
  groundScroll = (groundScroll + GROUND_SCROLL_SPEED * dt) % groundWidth
end

function love.keypressed(key)
  if key == 'escape' then
    love.event.quit()
  end

end
