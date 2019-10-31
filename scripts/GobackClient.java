import java.util.*;
import java.net.*;
import java.io.*;
public class GobackClient {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		Socket s=new Socket("localhost",4001);
		DataInputStream in=new DataInputStream(s.getInputStream());
		DataOutputStream out=new DataOutputStream(s.getOutputStream());
		Scanner sc=new Scanner(System.in);
		int frame_size=10,m,res,val=0;
		double wind;
		m=in.readInt();
		wind=(Math.pow(2,m))-1;
		int []a=new int[frame_size];
		for(int i=0;i<a.length;i++)
		{
			if((i-val)%wind==0 && i>0)
			{
				System.out.println("Enter 1 if you've received all the frames:\n");
				res=sc.nextInt();
				out.writeInt(res);
				if(res!=1)
				{
					int j;
					System.out.println("Enter the frame that you didn't receive:\n");
					res=sc.nextInt();
					out.writeInt(res);
					//System.out.println("lets retransmit it:\n");
					for(j=res-1;j<res-1+wind;j++)
					{
						a[j]=in.readInt();
						System.out.println("received frame" + (j+1) + "is" + a[j]);
					}
					i=j;
					val=(res-1)/(int)wind;
					continue;
				}
				else
				{
					int j;
					System.out.println("Acknowledgement has been sent for" + i);
					int res1=in.readInt();
					if(res1==1)
						System.out.println("acknowledgement received\n");
					else
					{
						System.out.println("Acknowledgement not received\n");
						for(j=i-(int)wind;j<i;j++)
						{
							a[j]=in.readInt();
							System.out.println("received frame(1)" + (j+1) + "is" + a[j]);
						}
						i=j;
						continue;
					}
				}
			}
			if(i==a.length)
				break;
			a[i]=in.readInt();
			System.out.println("received frame from server" + i);
		}
		in.close();
		out.close();
		sc.close();
		s.close();
	}

}
