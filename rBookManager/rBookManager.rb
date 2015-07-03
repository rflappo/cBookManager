require_relative 'rBook.rb'

class RBookManager
  attr_accessor :_library, :_searchResults, :_categories #arrays.
  attr_accessor :_lastUpdate, :_filePath #strings.
  attr_accessor :_searchFlag, :_anyChange #booleans.

  def initialize()
  end

  def initialize(strDBFilePath)
    #que cargue el archivo y settee los RBooks.
  end
  
end
