Pipe = {}

PIPE_IMAGE = love.graphics.newImage("assets/Image/pipe.png")

function Pipe:init()
  local obj = {}
  setmetatable(obj, self)
  self.__index = self

  obj.x = VIRTUAl_WIDTH
  obj.y = math.random(VIRTUAl_HEIGHT / 2, VIRTUAl_HEIGHT - 10)

  obj.width = PIPE_IMAGE:getWidth()

  return obj
end

function Pipe:update(dt)
  self.x = self.x + PIPE_SCROLL * dt
end

function Pipe:render()
  love.graphics.draw(PIPE_IMAGE, self.x, self.y)
end
