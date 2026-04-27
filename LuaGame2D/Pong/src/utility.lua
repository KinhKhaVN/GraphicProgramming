function drawWinner(player1, player2)
  local winner = (player1.score == THRESHOLD) and 
                 player1            or
                 player2

  
  love.graphics.print(winner.name.." won", WINDOW_WIDTH / 2 - 110, WINDOW_HEIGHT / 2 - 200)
  love.graphics.setFont(smallFont)
  love.graphics.printf("Press Enter to start new game", 0, WINDOW_HEIGHT / 2 - 140, WINDOW_WIDTH, "center")
  love.graphics.setFont(largeFont)
end

function drawPlayerScore(score, x, y)

  love.graphics.printf(tostring(score), 0, x, y, "center")
end

function displayFPS()
--  love.graphics.setFont(smallFont)
  love.graphics.setColor(0, 1, 0, 1)
  love.graphics.print("FPS: " .. tostring(love.timer.getFPS()), 20, 10)
  love.graphics.print("Score to win: " .. tostring(THRESHOLD), WINDOW_WIDTH * 0.65, 10)
  love.graphics.setColor(1, 1, 1, 1)
end
