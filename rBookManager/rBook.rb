class RBook
  attr_accessor :_title, :_author, :_pages, :_editorial, :_isbn, :_info
  attr_accessor :_price, :_stock, :_idCategory

  def initialize()
  end

  def initialize(hashJsonBook) #hashJsonBook it is a hash.
    @_title = hashJsonBook[:title]
    @_author = hashJsonBook[:author]
    @_pages = hashJsonBook[:pages]
    @_editorial = hashJsonBook[:editorial]
    @_isbn = hashJsonBook[:isbn]
    @_info = hashJsonBook[:info]
    @_price = hashJsonBook[:price]
    @_stock = hashJsonBook[:stock]
    @_idCategory = hashJsonBook[:category]
  end

  def getHashJsonBook()
    auxHash = Hash.new
    auxHash = {:title => @_title, :author => @_author, :editorial => @_editorial, :pages => @_pages, :isbn => @_isbn, :info => @_info, :price => @_price, :stock => @_stock, :category => @_idCategory}
  end

  def setHashJsonBook(hashJsonBook)
      @_title = hashJsonBook[:title]
      @_author = hashJsonBook[:author]
      @_pages = hashJsonBook[:pages]
      @_editorial = hashJsonBook[:editorial]
      @_isbn = hashJsonBook[:isbn]
      @_info = hashJsonBook[:info]
      @_price = hashJsonBook[:price]
      @_stock = hashJsonBook[:stock]
      @_idCategory = hashJsonBook[:category]
  end
end
