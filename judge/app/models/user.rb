  require 'digest'
class User < ActiveRecord::Base
  attr_accessible :code, :email, :encrypted_password, :name
  attr_accessor :password
  
  before_save :encrypt_new_password
  has_many :submission ,  :dependent => :destroy

  has_and_belongs_to_many :roles
  validates :password, {:confirmation => true, :length=>{:within => 6..50},
    :presence => true, :if => :password_required?}
  validates :email, {:presence=>true, :format => {:with => /^[^@][\w.-]+@[\w.-]+[.][a-z]{2,4}$/i}}

  def has_roles(roles)
    rids = role_ids & roles
    return rids.count>0
  end

  def authenticated?(password)
    return self.encrypted_password == encrypt(password)
  end

  def self.authenticate(params)
    user = User.find_by_email(params[:email])
    if user and user.authenticated?(params[:password])
      return user
    else
      return nil
    end
  end
  
  def self.roles
    return {:root => [1], :psetter=>[1,2], :g_user => [1,2,3]}
  end
  
  def self.roles2
    [['root',1],['problem setter',2],['general user',3]]
  end
  
  def self.newMA(params)
    u = User.new
    u.updateMA(params)    
    u.roles << Role.find(3)
    return u
  end

  def updateMA(params)
    self.name = params[:name]
    self.email = params[:email]
    self.password = params[:password]
    self.password_confirmation = params[:password_confirmation]
    self.code = params[:code]
    self.role_ids = params[:roles]
    return self.save
  end

  protected

  def encrypt_new_password
    if not password.blank?
      self.encrypted_password = encrypt(password)
    end
  end

  def password_required?
    return encrypted_password.blank? || password.present?
  end

  def encrypt(str)
    return Digest::SHA256.hexdigest(str)
  end
end
