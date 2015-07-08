require 'dm-core'
require 'dm-migrations'

DataMapper.setup(:default, "sqlite3://#{Dir.pwd}/bookdata.db")

class Book
  include DataMapper::Resource

  property :_id, Serial
  property :_title, String
  property :_author, String
  property :_pages, Integer
  property :_editorial, String
  property :_isbn, String
  property :_info, Text, :length => 500000
  property :_price, Float
  property :_stock, Integer
  property :_idCategory, Integer #it's the Category fkey.

end

DataMapper.finalize
