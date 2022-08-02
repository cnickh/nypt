package imp;

public interface Symmetric{

  public byte[] createKey(int length);

  public byte[] encrypt(byte[] key, byte[] open);

  public byte[] decrypt(byte[] key, byte[] close);

}
