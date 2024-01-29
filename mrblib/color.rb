class Color < Struct
  attr_accessor :r
  attr_accessor :g
  attr_accessor :b
  attr_accessor :a

  # @param r [Float]
  # @param g [Float]
  # @param b [Float]
  # @param a [Float]
  def initialize(r, g, b, a)
    @r = r
    @g = g
    @b = b
    @a = a
  end

  def to_s
    "{ R:#{self.r} G:#{self.g} B:#{self.b} A:#{self.a} }"
  end

  # @param other [Color]
  # @return [Color]
  def +(other)
    Color.new(self.r + other.r, self.g + other.g, self.b + other.b, self.a + other.a)
  end

  # @param other [Color]
  # @return [Color]
  def -(other)
    Color.new(self.r - other.r, self.g - other.g, self.b - other.b, self.a - other.a)
  end

  # @param other [Color] [Numeric]
  # @return [Color]
  def *(other)
    return self * Color.new(other, other, other, other) if other.is_a? Numeric
    Color.new(self.r * other.r, self.g * other.g, self.b * other.b, self.a * other.a)
  end

  # @param other [Color]
  # @return [Color]
  def /(other)
    return self / Color.new(other, other, other, other) if other.is_a? Numeric
    Color.new(self.r / other.r, self.g / other.g, self.b / other.b, self.a / other.a)
  end

  # @param other [Color]
  # @return [Color]
  def ==(other)
    self.r == other.r && self.g == other.g && self.b == other.b && self.a == other.a
  end

  # @param other [Color]
  # @return [Boolean]
  def !=(other)
    self.r != other.r || self.g != other.g || self.b != other.b || self.a != other.a
  end

end
  