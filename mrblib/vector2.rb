class Vector2 < Struct
  attr_accessor :x
  attr_accessor :y

  # @param x [Float]
  # @param y [Float]
  def initialize(x, y)
    @x = x
    @y = y
  end

  # @param value [Vector2]
  # @return [Vector2]
  def Vector2.normalize(value)
    value * (1.0 / value.length)
  end

  # @param value1 [Vector2]
  # @param value2 [Vector2]
  # @return [Float]
  def Vector2.distance(value1, value2)
    Math.sqrt((value1.x - value2.x) ** 2 + (value1.y - value2.y) ** 2)
  end

  # @param value1 [Vector2]
  # @param value2 [Vector2]
  # @return [Float]
  def Vector2.dot(value1, value2)
    value1.x * value2.x + value1.y * value2.y
  end

  # @param value1 [Vector2]
  # @param value2 [Vector2]
  # @param amount [Float]
  # @return [Vector2]
  def Vector2.lerp(value1, value2, amount)
    Vector2.new(value1.x + (value2.x - value1.x) * amount, value1.y + (value2.y - value1.y) * amount)
  end

  # @param value1 [Vector2]
  # @param value2 [Vector2]
  # @param amount [Float]
  # @return [Vector2]
  def Vector2.smooth_step(value1, value2, amount)
    if amount > 1.0
      amount = 1.0
    elsif amount < 0
      amount = 0
    end
    amount = (amount ** 2) * (3.0 - 2.0 * amount)
    Vector2.new(value1.x + (value2.x - value1.x) * amount, value1.y + (value2.y - value1.y) * amount)
  end

  # @param vector [Vector2]
  # @param normal [Vector2]
  # @return [Vector2]
  def Vector2.reflect(vector, normal)
    num = vector.x * normal.x + vector.y * normal.y
    Vector2.new(vector.x - 2.0 * num * normal.x, vector.y + 2.0 * num * normal.y)
  end

  def to_s
    "{ X:#{self.x} Y:#{self.y} }"
  end

  # Length of vector
  # @return [Float]
  def length
    Math.sqrt(@x * @x + @y * @y)
  end

  # @return [Vector2]
  def normalized
    self * (1.0 / length)
  end

  # @param other [Vector2]
  # @return [Vector2]
  def +(other)
    Vector2.new(self.x + other.x, self.y + other.y)
  end

  # @param other [Vector2]
  # @return [Vector2]
  def -(other)
    Vector2.new(self.x - other.x, self.y - other.y)
  end

  # @param other [Vector2] [Numeric]
  # @return [Vector2]
  def *(other)
    return self * Vector2.new(other, other) if other.is_a? Numeric
    Vector2.new(self.x * other.x, self.y * other.y)
  end

  # @param other [Vector2]
  # @return [Vector2]
  def /(other)
    return self / Vector2.new(other, other) if other.is_a? Numeric
    Vector2.new(self.x / other.x, self.y / other.y)
  end

  # @param other [Vector2]
  # @return [Boolean]
  def ==(other)
    self.x == other.x && self.y == other.y
  end

  # @param other [Vector2]
  # @return [Boolean]
  def !=(other)
    self.x != other.x || self.y != other.y
  end

end
