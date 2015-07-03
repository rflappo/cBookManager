class RBook
  attr_accessor :_title, :_author, :_pages, :_editorial, :_isbn, :_info
  attr_accessor :_price, :_stock, :_idCategory

  def initialize()
  end

  def initialize(jsonBook)
    @_title = jsonBook[:title]
    @_author = jsonBook[:author]
    @_pages = jsonBook[:pages]
    @_editorial = jsonBook[:editorial]
    @_isbn = jsonBook[:isbn]
    @_info = jsonBook[:info]
    @_price = jsonBook[:price]
    @_stock = jsonBook[:stock]
    @_idCategory = jsonBook[:category]
  end

  def getJsonBook()
    auxHash = Hash.new
    auxHash = {:title => @_title, :author => @_author, :editorial => @_editorial, :pages => @_pages, :isbn => @_isbn, :info => @_info, :price => @_price, :stock => @_stock, :category => @_idCategory}
  end

  def setJsonBook(jsonBook)
      @_title = jsonBook[:title]
      @_author = jsonBook[:author]
      @_pages = jsonBook[:pages]
      @_editorial = jsonBook[:editorial]
      @_isbn = jsonBook[:isbn]
      @_info = jsonBook[:info]
      @_price = jsonBook[:price]
      @_stock = jsonBook[:stock]
      @_idCategory = jsonBook[:category]
  end
end
