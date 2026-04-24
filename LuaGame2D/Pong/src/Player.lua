Player = {}

function Player:init(x, y, width, height)
  local obj = {}
  setmetatable(obj, self)
  self.__index = self

  obj.x      = x
  obj.y      = y
  obj.width  = width
  obj.height = height
  obj.dy     = 0
  obj.score  = 0

  return obj
end

function Player:reset()
  self.x = WINDOW_WIDTH / 2
  self.y = WINDOW_HEIGHT / 2
  self.dx = math.random(2) == 1 and -100 or 100
  self.dy = math.random(-50, 50)
end

function Player:update(dt)
  if self.dy < 0 then
    self.y = math.max(0, self.y + ( self.dy * dt ))
  else
    self.y = math.min(WINDOW_HEIGHT - self.height, self.y + ( self.dy * dt))
  end

end

function Player:render()
  love.graphics.rectangle("fill", self.x, self.y, self.width, self.height)
end





