require_relative 'rBook.rb'

#monkey patching
class Fixnum
  def seconds
    self
  end
  def minutes
    self * 60
  end
  def hours
    self * 60 * 60
  end
  def days
    self * 60 * 60 * 24
  end
end

# Falta :
#
class RBookManager
  private

  def _resetStateVar()
    @_anyChange = false
    @_searchFlag = false
    @_searchResults = Array.new
    @_library = Array.new
    @_categories = Array.new
  end

  def _checkIntegrityCategoryFile() #boolean
  end

  def _changeSearchStatusMode()

  end

  def _setLastUpdate(epoch_time) #sets last time modified
    #epoch_time is number of seconds since "UNIX time epoch"
  end

  def _addHashJsonBook(hashJsonBook) #just for db loading purposes
    bookToAdd = RBook.new(hashJsonBook)
    @_library << bookToAdd
  end

  def _saveDB()
    #save data on @_filePath
  end

  public

  def initialize()
    @_filePath = ""
    @_lastUpdate = ""
    @_anyChange = false
    @_searchFlag = false
    @_searchResults = Array.new
    @_library = Array.new
    @_categories = Array.new
  end

  def initialize(strDBFilePath) #will return the file path on success.
    @_filePath = strDBFilePath unless strDBFilePath.class.to_s != "String"
    #load all data
  end

  def getLastUpdate() #returns the last update date-time
    @_lastUpdate
  end

  def openDB(strDBFilePath) #returns number of records in file.
    unless strDBFilePath.class.to_s != "String"
      #abrir el archivo
        #self._resetStateVar()
        #settear variables @_lastUpdate y cargar @_library
    end
  end

  def addBook(rBook) #returns number of records in library.
    #it sould look for redundanse
    unless #redundanse
      #agregar libro. @_library << rBook
    end
  end

  def getBook(intId)
    @_library[intId] unless @_library.size() < (intId -= 1)
  end

  def removeBook(intId) #removes book from library by id.
    @_library.delete_at(intId) if @_library.size > intId
  end

  def replaceBook(intId, rBook)
    @_library[intId] = rBook unless intId >= @_library.size
  end

  def getLibrarySize()
    @_library.size
  end

  def emptyData()
    self._resetStateVar()
  end

  def saveDB()
  self._saveDB()
  end

  def saveDB(strDBFilePath)
    unless strDBFilePath.class.to_s != "String"
      @_filePath = strDBFilePath
      self._setLastUpdate()
      self._saveDB()
    end
  end

end
