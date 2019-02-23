class Rectangle < Struct
    attr_accessor :x
    attr_accessor :y
    attr_accessor :width
    attr_accessor :height
  
    # @param x [Fixnum]
    # @param y [Fixnum]
    # @param width [Fixnum]
    # @param height [Fixnum]
    def initialize(x, y, width, height)
      @x = x
      @y = y
      @width = width
      @height = height
    end
  
    def to_s
      "{ X:#{self.x} Y:#{self.y} Width:#{self.width} Height:#{self.height} }"
    end

    def left @x end
    def right @x + @width end
    def top @y end
    def bottom @y + @height end

    def center
      [self.x + self.width / 2, self.y + self.height / 2]
    end

    # @param x [Fixnum]
    # @param y [Fixnum]
    def contain(x, y)
      self.x <= x && x < self.x + self.width && self.y <= y && y < self.y + self.height
    end

    # @param other [Rectangle]
    def intersects(other)
      other.left < self.right && self.left < other.right && other.top < self.bottom && self.top < other.bottom
    end
    
    # @param other [Rectangle]
    # @return [Rectangle]
    def +(other)
      Rectangle.new(self.x + other.x, self.y + other.y, self.width + other.width, self.height + other.height)
    end
  
    # @param other [Rectangle]
    # @return [Rectangle]
    def -(other)
      Rectangle.new(self.x - other.x, self.y - other.y, self.width - other.width, self.height - other.height)
    end
  
    # @param other [Rectangle] [Numeric]
    # @return [Rectangle]
    def *(other)
      return self * Rectangle.new(other, other, other, other) if other.is_a? Numeric
      Rectangle.new(self.x * other.x, self.y * other.y, self.width * other.width, self.height * other.height)
    end
  
    # @param other [Rectangle]
    # @return [Rectangle]
    def /(other)
      return self / Rectangle.new(other, other, other, other) if other.is_a? Numeric
      Rectangle.new(self.x / other.x, self.y / other.y, self.width / other.width, self.height / other.height)
    end
  
    # @param other [Rectangle]
    # @return [Boolean]
    def ==(other)
      self.x == other.x && self.y == other.y && self.width == other.width && self.height == other.height
    end
  
    # @param other [Rectangle]
    # @return [Boolean]
    def !=(other)
      self.x != other.x || self.y != other.y || self.width != other.width || self.height != other.height
    end
  
  end
  